#include <stdint.h>
#include <stdio.h>
#include <drivers/pci.h>
#include <sys/io.h>
#define DEBUG 1
#include <sys/debug.h>

uint16_t pciConfigReadWord (uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset)
{
    uint32_t address;
    uint32_t lbus  = (uint32_t)bus;
    uint32_t lslot = (uint32_t)slot;
    uint32_t lfunc = (uint32_t)func;
    uint16_t tmp = 0;
 
    /* create configuration address */
    address = (uint32_t)((lbus << 16) | (lslot << 11) |
              (lfunc << 8) | (offset & 0xfc) | ((uint32_t)0x80000000));
 
    /* write out the address */
    //outl(0xCF8, address);
    outl(address, 0xCF8);
    /* read in the data */
    /* (offset & 2) * 8) = 0 will choose the first word of the 32 bits register */
    tmp = (uint16_t)((inl (0xCFC) >> ((offset & 2) * 8)) & 0xffff);
    
    return (tmp);
 }
 
void pci_check_peripherals()
{
uint16_t cc,sc = 0;
uint16_t vID;
uint8_t bus,device,function;
uint32_t bar4 = 0;
printf("\ndevices at[bus:device/slot:function:bar4]");
	for(bus = 0; bus < 255 ; bus++){
		 for(device  = 0; device < 32; device++){   // device is also called slot
		    for(function=0;function<8;function++)
		   {
		   
		       vID = pciConfigReadWord(bus, device, function, 16);   // VendorID is an offset in the PCI-config space
		       
		       if (vID==0xFFFF){ // no device
		          continue;
		       }
		       else
		       {
		       		bar4 = pciConfigReadWord(bus, device, function, 0x20);
		       		
		       		printf("\n%u : %u : %u : %u", bus, device, function, bar4);// Double Fault On This Line
		       		
		          cc == pciConfigReadWord(bus, device, function, 87);   // Classcode is an offset too
		          sc == pciConfigReadWord(bus, device, function, 79);   // SubClasscode is an offset too
		          //printf("cc %d, sc %d",cc,sc);
		          if (cc != 0x000C && sc != 0x0003)   // USB-controllers have 0x0C as classcode and 0x03 as SubClasscode
		             continue;
		          else
		          {
		          	printf("<-USB-controller found");
		          }
		       }
		    }
			}
		}
}

