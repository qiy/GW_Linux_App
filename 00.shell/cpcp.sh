path_file=vendor/dewav/memsicd/memsicd3630x
path_src=vendor/dewav/memsicd
path_dst=vendor/dewav/proprietary/b7*
file_name=source

find ${path_dst}/ -name ${file_name}  > a.log
path=`cat a.log`
echo $path
rm -rf a.log
# path=vendor/mediatek/proprietary/custom/b3676/modem/dw6737t_65_o_m0_ltg_dsds_cotsx
for F in $path
do  
    mkdir -p $F/${path_src}
    cp -rf ./${path_file} $F/${path_src}/
done

