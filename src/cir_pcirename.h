/*
 * Copyright 2007 George Sapountzis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * Macros for porting drivers from legacy xfree86 PCI code to the pciaccess
 * library. The main purpose being to facilitate source code compatibility.
 */

#ifndef CIRPCIRENAME_H
#define CIRPCIRENAME_H

enum region_type {
    REGION_MEM,
    REGION_IO
};

#include "xf86Module.h"

typedef struct pci_device *pciVideoPtr;

#define PCI_DEV_VENDOR_ID(_pcidev) ((_pcidev)->vendor_id)
#define PCI_DEV_DEVICE_ID(_pcidev) ((_pcidev)->device_id)
#define PCI_DEV_REVISION(_pcidev)  ((_pcidev)->revision)

#define PCI_SUB_VENDOR_ID(_pcidev) ((_pcidev)->subvendor_id)
#define PCI_SUB_DEVICE_ID(_pcidev) ((_pcidev)->subdevice_id)

/* pci-rework functions take a 'pci_device' parameter instead of a tag */
#define PCI_DEV_TAG(_pcidev)        (_pcidev)

/* PCI_DEV macros, typically used in printf's, add domain ? XXX */
#define PCI_DEV_BUS(_pcidev)       ((_pcidev)->bus)
#define PCI_DEV_DEV(_pcidev)       ((_pcidev)->dev)
#define PCI_DEV_FUNC(_pcidev)      ((_pcidev)->func)

/* pci-rework functions take a 'pci_device' parameter instead of a tag */
#define PCI_CFG_TAG(_pcidev)        (_pcidev)

/* PCI_CFG macros, typically used in DRI init, contain the domain */
#define PCI_CFG_BUS(_pcidev)      (((_pcidev)->domain << 8) | \
                                    (_pcidev)->bus)
#define PCI_CFG_DEV(_pcidev)       ((_pcidev)->dev)
#define PCI_CFG_FUNC(_pcidev)      ((_pcidev)->func)

#define PCI_REGION_BASE(_pcidev, _b, _type) ((_pcidev)->regions[(_b)].base_addr)
#define PCI_REGION_SIZE(_pcidev, _b)        ((_pcidev)->regions[(_b)].size)

#define PCI_READ_BYTE(_pcidev, _value_ptr, _offset) \
    pci_device_cfg_read_u8((_pcidev), (_value_ptr), (_offset))

#define PCI_READ_LONG(_pcidev, _value_ptr, _offset) \
    pci_device_cfg_read_u32((_pcidev), (_value_ptr), (_offset))

#define PCI_WRITE_LONG(_pcidev, _value, _offset) \
    pci_device_cfg_write_u32((_pcidev), (_value), (_offset))

#ifndef _XF86_PCIINFO_H

#define PCI_VENDOR_CIRRUS		0x1013
/* Cirrus Logic */
#define PCI_CHIP_GD7548			0x0038
#define PCI_CHIP_GD7555			0x0040
#define PCI_CHIP_GD7556                 0x004C
#define PCI_CHIP_GD5430			0x00A0
#define PCI_CHIP_GD5434_4		0x00A4
#define PCI_CHIP_GD5434_8		0x00A8
#define PCI_CHIP_GD5436			0x00AC
#define PCI_CHIP_GD5446			0x00B8
#define PCI_CHIP_GD5480			0x00BC
#define PCI_CHIP_GD5462			0x00D0
#define PCI_CHIP_GD5464			0x00D4
#define PCI_CHIP_GD5464BD		0x00D5
#define PCI_CHIP_GD5465			0x00D6
#define PCI_CHIP_6729			0x1100
#define PCI_CHIP_6832			0x1110
#define PCI_CHIP_GD7542			0x1200
#define PCI_CHIP_GD7543			0x1202
#define PCI_CHIP_GD7541			0x1204

#endif
#endif /* CIRPCIRENAME_H */
