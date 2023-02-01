#!/bin/bash 
# b_t 0;b_w 1;a_t 2;a_w 3;
flag=${1}

if [ 0 == $flag ];then
   # echoMsg "dw" 4   
    find vendor/mediatek/proprietary/custom/b36*/modem/dw6737t_65_o_m0_lt*/* | xargs rm
    find vendor/mediatek/proprietary/custom/b36*/modem/ -name dw6737t_65_o_m0_lt* > a.log
    path=`cat a.log`
    echo $path
    rm -rf a.log
    # path=vendor/mediatek/proprietary/custom/b3676/modem/dw6737t_65_o_m0_ltg_dsds_cotsx
    for F in $path
    do  
        cp -rf modem_mp_b36/temp_modem/* $F
    done
fi

if [ 1 == $flag ];then       
#    echoMsg "dt" 4    
    find vendor/mediatek/proprietary/custom/b36*/modem/dw6737t_65_o_m0_lw*/* | xargs rm
    find vendor/mediatek/proprietary/custom/b36*/modem/ -name dw6737t_65_o_m0_lw* > a.log
    path=`cat a.log`
    echo $path
    rm -rf a.log
    # path=vendor/mediatek/proprietary/custom/b3676/modem/dw6737t_65_o_m0_ltg_dsds_cotsx
    for F in $path
    do  
        cp -rf modem_mp_b36/temp_modem/* $F
    done
fi

if [ 2 == $flag ];then
   # echoMsg "dw" 4   
    find vendor/mediatek/proprietary/custom/a36*/modem/dw6737t_65_o_m0_lt*/* | xargs rm
    find vendor/mediatek/proprietary/custom/a36*/modem/ -name dw6737t_65_o_m0_lt* > a.log
    path=`cat a.log`
    echo $path
    rm -rf a.log
    # path=vendor/mediatek/proprietary/custom/a3676/modem/dw6737t_65_o_m0_ltg_dsds_cotsx
    for F in $path
    do  
        cp -rf modem_mp_a36/temp_modem/* $F
    done
fi

if [ 3 == $flag ];then    
#    echoMsg "dt" 4    
    find vendor/mediatek/proprietary/custom/a36*/modem/dw6737t_65_o_m0_lw*/* | xargs rm
    find vendor/mediatek/proprietary/custom/a36*/modem/ -name dw6737t_65_o_m0_lw* > a.log
    path=`cat a.log`
    echo $path
    rm -rf a.log
    # path=vendor/mediatek/proprietary/custom/a3676/modem/dw6737t_65_o_m0_ltg_dsds_cotsx
    for F in $path
    do  
        cp -rf modem_mp_a36/temp_modem/* $F
    done
fi













