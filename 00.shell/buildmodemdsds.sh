#! /bin/bash
MODEM_BASE_CODE=modem_mp_a36
#################################################################################
## a36 common open ##
#################################################################################
 rm -rf ./${MODEM_BASE_CODE}/build  ./${MODEM_BASE_CODE}/build_internal ./${MODEM_BASE_CODE}/temp_modem/
 git checkout ./${MODEM_BASE_CODE}/

cd ./${MODEM_BASE_CODE}/
./make.sh "DW6737T_65_O_M0(LWG_DSDS).mak"  new
RET=$(echo $?)
if [ "${RET}" != "0" ];then
	echo "build error!!"
    	cd ../
	git checkout ./${MODEM_BASE_CODE}/
	exit 1;
fi
cd ../
./device/mediatek/build/build/tools/modemRenameCopy.pl ./${MODEM_BASE_CODE}/ "DW6737T_65_O_M0(LWG_DSDS).mak" 

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

# ltg #
cd ./${MODEM_BASE_CODE}/
./make.sh "DW6737T_65_O_M0(LTG_DSDS).mak"  new
RET=$(echo $?)
if [ "${RET}" != "0" ];then
	echo "build error!!"
    	cd ../
	git checkout ./${MODEM_BASE_CODE}/
	exit 1;
fi
cd ../
./device/mediatek/build/build/tools/modemRenameCopy.pl ./${MODEM_BASE_CODE}/ "DW6737T_65_O_M0(LTG_DSDS).mak" 
    
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

 rm -rf ./${MODEM_BASE_CODE}/build ./${MODEM_BASE_CODE}/build_internal ./${MODEM_BASE_CODE}/temp_modem/
 git checkout ./${MODEM_BASE_CODE}/
#################################################################################
 ## a36 common end ##
#################################################################################
## a3658_dtac open  ##
MODEM_SRC=custom_a36_dtac
cp -rf modem_mp_a36/${MODEM_SRC}/modem/ modem_mp_a36/custom/
cd ./${MODEM_BASE_CODE}/

./make.sh "DW6737T_65_O_M0(LWG_DSDS).mak"  new
RET=$(echo $?)
if [ "${RET}" != "0" ];then
	echo "build error!!"
    	cd ../
	git checkout ./${MODEM_BASE_CODE}/
	exit 1;
fi
cd ../
./device/mediatek/build/build/tools/modemRenameCopy.pl ./${MODEM_BASE_CODE}/ "DW6737T_65_O_M0(LWG_DSDS).mak" 

rm -rf vendor/mediatek/proprietary/custom/a3658/modem/dw6737t_65_o_m0_lwg_dsds_cotsx/*
cp -rf modem_mp_a36/temp_modem/* vendor/mediatek/proprietary/custom/a3658/modem/dw6737t_65_o_m0_lwg_dsds_cotsx/
# ltg #
cd ./${MODEM_BASE_CODE}/
./make.sh "DW6737T_65_O_M0(LTG_DSDS).mak"  new
RET=$(echo $?)
if [ "${RET}" != "0" ];then
	echo "build error!!"
    	cd ../
	git checkout ./${MODEM_BASE_CODE}/
	exit 1;
fi
cd ../
./device/mediatek/build/build/tools/modemRenameCopy.pl ./${MODEM_BASE_CODE}/ "DW6737T_65_O_M0(LTG_DSDS).mak" 

rm -rf vendor/mediatek/proprietary/custom/a3658/modem/dw6737t_65_o_m0_ltg_dsds_cotsx/*
cp -rf modem_mp_a36/temp_modem/* vendor/mediatek/proprietary/custom/a3658/modem/dw6737t_65_o_m0_ltg_dsds_cotsx/

 rm -rf ./${MODEM_BASE_CODE}/build ./${MODEM_BASE_CODE}/build_internal ./${MODEM_BASE_CODE}/temp_modem/
 git checkout ./${MODEM_BASE_CODE}/
#################################################################################
## a3658_dtac end ##
#################################################################################
## a3698_four open  ##
MODEM_SRC=custom_a36_four
cp -rf modem_mp_a36/${MODEM_SRC}/* modem_mp_a36/custom/modem/ 
cd ./${MODEM_BASE_CODE}/

./make.sh "DW6737T_65_O_M0(LWG_DSDS).mak"  new
RET=$(echo $?)
if [ "${RET}" != "0" ];then
	echo "build error!!"
    	cd ../
	git checkout ./${MODEM_BASE_CODE}/
	exit 1;
fi
cd ../
./device/mediatek/build/build/tools/modemRenameCopy.pl ./${MODEM_BASE_CODE}/ "DW6737T_65_O_M0(LWG_DSDS).mak" 

rm -rf vendor/mediatek/proprietary/custom/a3698/modem/dw6737t_65_o_m0_lwg_dsds_cotsx/*
cp -rf modem_mp_a36/temp_modem/* vendor/mediatek/proprietary/custom/a3698/modem/dw6737t_65_o_m0_lwg_dsds_cotsx/
# ltg #
cd ./${MODEM_BASE_CODE}/
./make.sh "DW6737T_65_O_M0(LTG_DSDS).mak"  new
RET=$(echo $?)
if [ "${RET}" != "0" ];then
	echo "build error!!"
    	cd ../
	git checkout ./${MODEM_BASE_CODE}/
	exit 1;
fi
cd ../
./device/mediatek/build/build/tools/modemRenameCopy.pl ./${MODEM_BASE_CODE}/ "DW6737T_65_O_M0(LTG_DSDS).mak" 

rm -rf vendor/mediatek/proprietary/custom/a3698/modem/dw6737t_65_o_m0_ltg_dsds_cotsx/*
cp -rf modem_mp_a36/temp_modem/* vendor/mediatek/proprietary/custom/a3698/modem/dw6737t_65_o_m0_ltg_dsds_cotsx/

 rm -rf ./${MODEM_BASE_CODE}/build ./${MODEM_BASE_CODE}/build_internal ./${MODEM_BASE_CODE}/temp_modem/
 git checkout ./${MODEM_BASE_CODE}/
#################################################################################
## a3698_four end ##
#################################################################################
## b36 common open ##
MODEM_SRC=custom_b36
cp -rf modem_mp_a36/${MODEM_SRC}/modem/ modem_mp_a36/custom/
cd ./${MODEM_BASE_CODE}/

./make.sh "DW6737T_65_O_M0(LWG_DSDS).mak"  new
RET=$(echo $?)
if [ "${RET}" != "0" ];then
	echo "build error!!"
    	cd ../
	git checkout ./${MODEM_BASE_CODE}/
	exit 1;
fi
cd ../
./device/mediatek/build/build/tools/modemRenameCopy.pl ./${MODEM_BASE_CODE}/ "DW6737T_65_O_M0(LWG_DSDS).mak" 

find vendor/mediatek/proprietary/custom/b36*/modem/dw6737t_65_o_m0_lw*/* | xargs rm
find vendor/mediatek/proprietary/custom/b36*/modem/ -name dw6737t_65_o_m0_lw* > a.log
path=`cat a.log`
echo $path
rm -rf a.log
# path=vendor/mediatek/proprietary/custom/a3676/modem/dw6737t_65_o_m0_ltg_dsds_cotsx
for F in $path
do  
    cp -rf modem_mp_a36/temp_modem/* $F
done

# ltg #
cd ./${MODEM_BASE_CODE}/
./make.sh "DW6737T_65_O_M0(LTG_DSDS).mak"  new
RET=$(echo $?)
if [ "${RET}" != "0" ];then
	echo "build error!!"
    	cd ../
	git checkout ./${MODEM_BASE_CODE}/
	exit 1;
fi
cd ../
./device/mediatek/build/build/tools/modemRenameCopy.pl ./${MODEM_BASE_CODE}/ "DW6737T_65_O_M0(LTG_DSDS).mak" 
    
find vendor/mediatek/proprietary/custom/b36*/modem/dw6737t_65_o_m0_lt*/* | xargs rm
find vendor/mediatek/proprietary/custom/b36*/modem/ -name dw6737t_65_o_m0_lt* > a.log
path=`cat a.log`
echo $path
rm -rf a.log
# path=vendor/mediatek/proprietary/custom/a3676/modem/dw6737t_65_o_m0_ltg_dsds_cotsx
for F in $path
do  
    cp -rf modem_mp_a36/temp_modem/* $F
done

 rm -rf ./${MODEM_BASE_CODE}/build ./${MODEM_BASE_CODE}/build_internal ./${MODEM_BASE_CODE}/temp_modem/
 git checkout ./${MODEM_BASE_CODE}/
#################################################################################
 ## b36 common end ##
#################################################################################
## b3698 open  ##
MODEM_SRC=custom_b3698
cp -rf modem_mp_a36/${MODEM_SRC}/modem/ modem_mp_a36/custom/
sed -i "s/#CUSTOM_OPTION\ +=\ __EPSK_TX_SW_SWITCH_OFF/CUSTOM_OPTION\ +=\ __EPSK_TX_SW_SWITCH_OFF__/g" modem_mp_a36/make/DW6737T_65_O_M0\(LWG_DSDS_COTSX\).mak
cd ./${MODEM_BASE_CODE}/

./make.sh "DW6737T_65_O_M0(LWG_DSDS_COTSX).mak"  new
RET=$(echo $?)
if [ "${RET}" != "0" ];then
	echo "build error!!"
    	cd ../
	git checkout ./${MODEM_BASE_CODE}/
	exit 1;
fi
cd ../
./device/mediatek/build/build/tools/modemRenameCopy.pl ./${MODEM_BASE_CODE}/ "DW6737T_65_O_M0(LWG_DSDS_COTSX).mak" 

rm -rf vendor/mediatek/proprietary/custom/b3698/modem/dw6737t_65_o_m0_lwg_dsds_cotsx/*
cp -rf modem_mp_a36/temp_modem/* vendor/mediatek/proprietary/custom/b3698/modem/dw6737t_65_o_m0_lwg_dsds_cotsx/

rm -rf ./${MODEM_BASE_CODE}/build ./${MODEM_BASE_CODE}/build_internal ./${MODEM_BASE_CODE}/temp_modem/
git checkout ./${MODEM_BASE_CODE}/
#################################################################################
## b3698  end ##
#################################################################################




