/*
 * Configuration for the AVM Fritz!Box 4040
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <configs/ipq40xx_cdp.h>

#define CONFIG_MODEL_FRITZ4040
#define CONFIG_MODEL		"FRITZ4040"
#define MTDIDS_DEFAULT		"nand0=nand0"
// Preliminary defs, watch out for possible calibration data at end of flash
#define MTDPARTS_DEFAULT	"mtdparts=nand0:512k(qcom)ro,2560k(u-boot)ro,9216k(firmware)"

#undef CONFIG_BOOTDELAY
#define CONFIG_BOOTDELAY 3

#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND		"boot"

#define CONFIG_EXTRA_ENV_SETTINGS				\
	"mtdids=" MTDIDS_DEFAULT "\0"				\
	"mtdparts=" MTDPARTS_DEFAULT "\0"			\
	"nandboot=nboot firmware && bootm\0"			\
	"tftpboot=tftpsrv && bootm; sleep 5; run tftpboot\0"	\
	"fritzboot=run nandboot || run tftpboot;\0"		\

#undef V_PROMPT
#define V_PROMPT		"(wAP60 G) # "

#define CONFIG_SERVERIP         192.168.1.70
#define CONFIG_NETMASK          255.255.255.0
#define CONFIG_BOOTFILE         CONFIG_MODEL ".bin"
#define CONFIG_LZO
#define CONFIG_LZMA
#define CONFIG_SYS_LONGHELP

#define CONFIG_CMD_MISC
#define CONFIG_CMD_ELF
#define CONFIG_CMD_IMI
#define CONFIG_CMD_LOADB
#define CONFIG_CMD_SPI
#define CONFIG_CMD_TFTPSRV
#define CONFIG_CMD_PCI
#define DEBUG 42

#define CONFIG_PCI
#define CONFIG_IPQ40XX_PCI

#ifndef CONFIG_FIT
#define CONFIG_FIT
#endif

#undef CONFIG_ENV_IS_IN_FLASH

#undef CONFIG_SYS_LOAD_ADDR
#define CONFIG_SYS_LOAD_ADDR    0x85000000

#undef CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_TEXT_BASE	0x84200000

#endif
