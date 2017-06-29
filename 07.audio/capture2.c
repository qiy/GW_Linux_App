#include <alsa/asoundlib.h>  
  
int main()  
{  
    int ret;  
    snd_pcm_t *pcm_handle;  
    snd_pcm_stream_t stream = SND_PCM_STREAM_CAPTURE;  
    snd_pcm_hw_params_t *hwparams;  
    char *pcm_name;  
  
    pcm_name = strdup("plughw:0,0");  
    /*分配在栈snd_pcm_hw_params_t结构。*/ 
    snd_pcm_hw_params_alloca(&hwparams);  
    /*打开PCM。此函数的最后一个参数是模式。*/ 
    ret = snd_pcm_open(&pcm_handle, pcm_name, stream, 0);  
    if (ret < 0) {  
        printf("snd_pcm_open failed\n");  
        return(-1);  
    }  
    /*初始化hwparams全配置空间*/ 
    ret = snd_pcm_hw_params_any(pcm_handle, hwparams);  
    if (ret < 0) {  
        printf("snd_pcm_hw_params_any failed\n");  
        return(-1);  
    }  
  
    int rate = 44100;  
    int exact_rate;  
    int dir;  
    int periods = 2;  
    snd_pcm_uframes_t periodsize = 8192;  
    /* Set access type. This can be either    */
    /* SND_PCM_ACCESS_RW_INTERLEAVED or       */
    /* SND_PCM_ACCESS_RW_NONINTERLEAVED.      */
    /* There are also access types for MMAPed */
    /* access, but this is beyond the scope   */
    /* of this introduction.                  */ 
    ret = snd_pcm_hw_params_set_access(pcm_handle, hwparams,   
            SND_PCM_ACCESS_RW_INTERLEAVED);  
    if (ret < 0) {  
        printf("snd_pcm_hw_params_set_access failed\n");  
        return(-1);  
    }  
    /* Set sample format */ 
    ret = snd_pcm_hw_params_set_format(pcm_handle, hwparams,   
            SND_PCM_FORMAT_S16_LE);  
    if (ret < 0) {  
        printf("snd_pcm_hw_params_set_format failed\n");  
        return(-1);  
    }  
    /* Set sample rate. If the exact rate is not supported */
    /* by the hardware, use nearest possible rate.         */  
    exact_rate = rate;  
    ret = snd_pcm_hw_params_set_rate_near(pcm_handle, hwparams,   
            &exact_rate, 0);  
    if (ret < 0) {  
        printf("snd_pcm_hw_params_set_rate_near failed\n");  
        return(-1);  
    }  
    if (rate != exact_rate) {  
        printf("The rate %d Hz is not supported by your hardware\n"  
                "==> Using %d Hz instead\n", rate, exact_rate);  
    }  
    /* Set number of channels */ 
    ret = snd_pcm_hw_params_set_channels(pcm_handle, hwparams, 2);  
    if (ret < 0) {  
        printf("snd_pcm_hw_params_set_channels failed\n");  
        return(-1);  
    }  
    /* Set number of periods. Periods used to be called fragments.片段式 */ 
    ret = snd_pcm_hw_params_set_periods(pcm_handle, hwparams, periods, 0);  
    if (ret < 0) {  
        printf("snd_pcm_hw_params_set_periods failed\n");  
        return(-1);  
    }  
    /* Set buffer size (in frames). The resulting latency is given by */
    /* latency = periodsize * periods / (rate * bytes_per_frame)     */ 
    ret = snd_pcm_hw_params_set_buffer_size(pcm_handle, hwparams,   
            (periodsize * periods) >> 2);  
    if (ret < 0) {  
        printf("snd_pcm_hw_params_set_buffer_size failed\n");  
        return(-1);  
    }  
 
    /* Apply HW parameter settings to */
    /* PCM device and prepare device  */ 
    ret = snd_pcm_hw_params(pcm_handle, hwparams);  
    if (ret < 0) {  
        printf("snd_pcm_hw_params failed\n");  
        return(-1);  
    }  

    /* Write num_frames frames from buffer data to    */ 
    /* the PCM device pointed to by pcm_handle.       */ 
    /* Returns the number of frames actually written. */
    unsigned char *data;  
    int l1, l2;  
    short s1, s2;  
    int frames;  
    /* allot 8192 bytes */ 
    data = malloc(periodsize);  
    frames = periodsize >> 2;  
  
    for (l1 = 0; l1 < 100; l1++) {  
//        for (l2 = 0; l2 < frames; l2++) {  
//            s1 = (l2 % 128) * 100 - 5000;  
//            s2 = (l2 % 256) * 100 - 5000;  
//            data[4*l2] = (unsigned char)s1;  
//            data[4*l2+1] = s1 >> 8;  
//            data[4*l2+2] = (unsigned char)s2;  
//            data[4*l2+3] = s2 >> 8;  
//        } 
       /*for the interleaved write access,and for 
        * the noninterleaved should snd_pcm_writen*/ 
        while ((ret = snd_pcm_readi(pcm_handle, data, frames)) < 0) { 
           /*restart pcm_handle*/ 
            snd_pcm_prepare(pcm_handle);  
            printf("<<<<<<<<<<<<<<Buffer Underrun>>>>>>>>>>>>\n");  
        }  
    }  
    /* Stop PCM device and drop pending frames */ 
    snd_pcm_drop(pcm_handle); 
    /* Stop PCM device after pending frames have been played */  
    snd_pcm_drain(pcm_handle);  
  
    return 0;  
}  
