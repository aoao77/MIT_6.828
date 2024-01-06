#ifndef JOS_KERN_E1000_H
#define JOS_KERN_E1000_H

#include<inc/types.h>

/* defination */
#define E1000_VERDOR_ID (0x8086)
#define E1000_DEVICE_ID (0x100E)

/* register */
#define STATUS  (0x0008/4)
#define TDBAL   (0x3800/4)  /* transmit descriptor base low */
#define TDBAH   (0x3804/4)  /* transmit descriptor base high */
#define TDLEN   (0x3808/4)  /* the num of bytes of transmit descriptor */
#define TDH     (0x3810/4)  /* transmit descriptor head (base + ptr * 16) */
#define TDT     (0x3818/4)  /* transmit descriptor tail */
#define TCTL    (0x0400/4)  /* transmit descriptor control */
#define TIPG    (0x0410/4)  /* transmit IPG intel packet gap */

#define TCTL_EN     (1)      /* the bit num */
#define TCTL_PSP    (3)      /* the bit num */
#define TCTL_CT_s   (4)      /* the bit num */
#define TCTL_CT_e   (11)      /* the bit num */
#define TCTL_COLD_s (12)      /* the bit num */
#define TCTL_COLD_e (21)      /* the bit num */

#define TIPG_IPGT   (0)      /* the bit num */
#define TIPG_IPGR1  (10)      /* the bit num */
#define TIPG_IPGR2  (20)      /* the bit num */

#define TD_CMD_EOP   (0)      /* the bit num */
#define TD_CMD_IFCS  (1)      /* the bit num */
#define TD_CMD_IC    (2)      /* the bit num */
#define TD_CMD_RS    (3)      /* the bit num */
#define TD_CMD_RSV   (4)      /* the bit num */
#define TD_CMD_DEXT  (5)      /* the bit num */
#define TD_CMD_VLE   (6)      /* the bit num */
#define TD_CMD_IDE   (7)      /* the bit num */

#define TD_STATUS_DD   (0)      /* the bit num */
#define TD_STATUS_EC   (1)      /* the bit num */
#define TD_STATUS_LC   (2)      /* the bit num */
#define TD_STATUS_RSV  (3)      /* the bit num */



#define MAX_TRANSMIT_DESCRIPTOR (64)
#define TRANSMIT_DESCRIPTOR_BYTE (16)
#define MAX_ETHERNET_PACKET     (1518)
// #define MAX_TRANSMIT_DESCRIPTOR (64)

struct transmit_descriptor
{
    uint64_t addr;
    uint16_t length;
    uint8_t  cso;
    uint8_t  cmd;
    uint8_t  status;
    uint8_t  css;
    uint16_t  special;
};


#endif  // SOL >= 6
