#ifndef __ARCH_ARM_MACH_MSM_PANTECH_SYS_H
#define __ARCH_ARM_MACH_MSM_PANTECH_SYS_H


#include <mach/msm_iomap.h>


/*******************************************************************************
**  Must have equal vendor/pantch/pantech_sys.h
**  and kernel/arch/arm/mach-msm/pantech_sys.h
*******************************************************************************/


/*******************************************************************************
**  RESET REASON ADDRESS DEFINE
*******************************************************************************/
#define PANTECH_RESET_REASON_ADDR                  0xFA00A6C4 //A:0x2A03F6C4
#define PANTECH_RESET_MAGIC_ADDR                    (PANTECH_RESET_REASON_ADDR - 0x4)

/*******************************************************************************
**  RESET MAGIC DEFINE
*******************************************************************************/
#define SYS_RESET_MAGIC     0xDEAD0525

/*******************************************************************************
**  RESET REASON DEFINE
*******************************************************************************/
#define SYS_RESET_REASON_MASK                      0xDA000000
#define SYS_RESET_USBDUMP_MASK                     0x00B00000
#define SYS_RESET_RAMDUMP_MASK                     0x000C0000

#define SYS_RESET_BACKLIGHT_OFF_FLAG               (0x1 << 15)
#define SYS_RESET_MDM_DUMP_FLAG                    (0x1 << 14)
#define SYS_RESET_SSR_MODE_FLAG                    (0x1 << 13)
#define SYS_RESET_SSR_NOTI_FLAG                    (0x1 << 12)
#define SYS_RESET_RESERVED_FLAG_11                 (0x1 << 11)
#define SYS_RESET_RESERVED_FLAG_10                 (0x1 << 10)
#define SYS_RESET_RESERVED_FLAG_9                  (0x1 << 9)
#define SYS_RESET_RESERVED_FLAG_8                  (0x1 << 8)
#define SYS_RESET_RESERVED_FLAG_7                  (0x1 << 7)
#define SYS_RESET_RESERVED_FLAG_6                  (0x1 << 6)
#define SYS_RESET_RESERVED_FLAG_5                  (0x1 << 5)
#define SYS_RESET_RESERVED_FLAG_4                  (0x1 << 4)
#define SYS_RESET_RESERVED_FLAG_3                  (0x1 << 3)
#define SYS_RESET_RESERVED_FLAG_2                  (0x1 << 2)
#define SYS_RESET_RESERVED_FLAG_1                  (0x1 << 1)
#define SYS_RESET_RESERVED_FLAG_0                  (0x1 << 0)

#define SYS_RESET_REASON_LINUX_MASK                0xDA000010
#define SYS_RESET_REASON_LINUX                     0xDA000011
#define SYS_RESET_REASON_USERDATA_FS               0xDA000012
#define SYS_RESET_REASON_DATA_MOUNT_ERR            0xDA000013       //20140509 p13795

#define SYS_RESET_REASON_WATCHDOG_MASK             0xDA000020
#define SYS_RESET_REASON_WATCHDOG_NSEC_BITE        0xDA000021
#define SYS_RESET_REASON_WATCHDOG_SEC_BITE         0xDA000022
#define SYS_RESET_REASON_WATCHDOG_NSEC_SEC_BITE    0xDA000023

#define SYS_RESET_REASON_ABNORMAL_MASK             0xDA000030
#define SYS_RESET_REASON_ABNORMAL                  0xDA000031

#define SYS_RESET_REASON_MDM_MASK                  0xDA000040
#define SYS_RESET_REASON_MDM                       0xDA000041

#define SYS_RESET_REASON_LPASS_MASK                0xDA000050
#define SYS_RESET_REASON_LPASS                     0xDA000051

#define SYS_RESET_REASON_DSPS_MASK                 0xDA000060
#define SYS_RESET_REASON_DSPS                      0xDA000061

#define SYS_RESET_REASON_RIVA_MASK                 0xDA000070
#define SYS_RESET_REASON_RIVA                      0xDA000071

// p15060
#define SYS_RESET_REASON_WIFI_MASK                 SYS_RESET_REASON_RIVA_MASK
#define SYS_RESET_REASON_WIFI                      SYS_RESET_REASON_RIVA

#define SYS_RESET_REASON_RPM_MASK                  0xDA000080
#define SYS_RESET_REASON_RPM_DOGBARK               0xDA000081
#define SYS_RESET_REASON_RPM_ERRFATAL              0xDA000082

#define SYS_RESET_REASON_VENUS_MASK                0xDA000090
#define SYS_RESET_REASON_VENUS                     0xDA000091

#define SYS_RESET_REASON_MODEM_MASK                0xDA0000A0
#define SYS_RESET_REASON_MODEM                     0xDA0000A1

#define SYS_RESET_REASON_NORMAL_MASK               0xDA0000F0
#define SYS_RESET_REASON_NORMAL                    0xDA0000F1

#define SET_SYS_RESET_MAGIC(x)                            (*((volatile unsigned int *)PANTECH_RESET_MAGIC_ADDR) = (x))
#define SET_SYS_RESET_REASON_CLEAR(x)              (*((volatile unsigned int *)PANTECH_RESET_REASON_ADDR) = (x))
#define SET_SYS_RESET_REASON_ERROR(x) \
do { \
    SET_SYS_RESET_MAGIC(SYS_RESET_MAGIC); \
    (*((volatile unsigned int *)PANTECH_RESET_REASON_ADDR) = ((*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR) & ~(0x000000FF))|(x)); \
} while(0)
#define SET_SYS_RESET_REASON_MODE(mode,on) \
do { \
    SET_SYS_RESET_MAGIC(SYS_RESET_MAGIC); \
    on ? (*((volatile unsigned int *)PANTECH_RESET_REASON_ADDR) = (*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR)|(mode)) : \
    (*((volatile unsigned int *)PANTECH_RESET_REASON_ADDR) = (*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR)& ~(mode)); \
} while(0)
#define SET_SYS_RESET_REASON_MODE_CLEAR(x)   (*((volatile unsigned int *)PANTECH_RESET_REASON_ADDR) = (*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR) & ~(0x00FF0000))
#define SET_SYS_RESET_REASON_FLAG(flag,on) \
do { \
    SET_SYS_RESET_MAGIC(SYS_RESET_MAGIC); \
    on ? (*((volatile unsigned int *)PANTECH_RESET_REASON_ADDR) = (*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR)|(flag)) : \
    (*((volatile unsigned int *)PANTECH_RESET_REASON_ADDR) = (*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR)& ~(flag)); \
} while(0)

#define IS_SYS_MAGIC                                             ((*(volatile unsigned int *)PANTECH_RESET_MAGIC_ADDR) == (SYS_RESET_MAGIC))
#define IS_SYS_USBDUMP_MODE                             IS_SYS_MAGIC && \
                                                                               ((*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR) & ~(0xFF0FFFFF)) == (SYS_RESET_USBDUMP_MASK)
#define IS_SYS_RAMDUMP_MODE                             IS_SYS_MAGIC && \
                                                                               ((*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR) & ~(0xFFF0FFFF)) == (SYS_RESET_RAMDUMP_MASK)
#define IS_SYS_RESET_AND_REBOOT                       IS_SYS_MAGIC && \
                                                                               ((*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR) & ~(0x00FFFFFF)) == (SYS_RESET_REASON_MASK)
#define IS_SYS_RESET                                             IS_SYS_MAGIC && \
                                                                               (((*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR) & ~(0x00FFFFFF)) == (SYS_RESET_REASON_MASK)) && \
                                                                               (((*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR) & ~(0x00FFFF0F)) != (SYS_RESET_REASON_NORMAL_MASK))

#define GET_SYS_RESET_REASON_GROUP                IS_SYS_MAGIC ? (*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR) & ~(0x00FFFF0F) : 0x0
#define GET_SYS_RESET_REASON_ERROR                IS_SYS_MAGIC ? (*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR) & ~(0x00FFFF00) : 0x0
#define GET_SYS_RESET_REASON_ALL                     IS_SYS_MAGIC ? (*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR) : 0x0
#define GET_SYS_RESET_REASON_FLAG(x)              IS_SYS_MAGIC ? ((*(volatile unsigned int *)PANTECH_RESET_REASON_ADDR) & (x)) == (x) : 0x0
#define GET_SYS_RESET_MAGIC                              (*(volatile unsigned int *)PANTECH_RESET_MAGIC_ADDR)

/*******************************************************************************
**  Reset Reason API (Kernel Only)
*******************************************************************************/
extern void pantech_sys_reset_reason_init(void);
extern void pantech_sys_reset_reason_set(unsigned int reason);
extern void pantech_sys_reset_backlight_flag_set(unsigned int flag);
extern unsigned int pantech_sys_reset_backlight_flag_get(void);
extern unsigned int pantech_sys_rst_is_silent_boot_mode(void);

extern void pantech_force_dump_key(unsigned int code, int value);
#endif
