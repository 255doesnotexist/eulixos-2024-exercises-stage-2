#include <linux/fs.h>
#include <linux/module.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "mychardev"
#define DEFAULT_MESSAGE "Default message from virtual character device!\n"

static int major;
static char *message = DEFAULT_MESSAGE;
static char *message_ptr;

module_param (message, charp, S_IRUGO);
MODULE_PARM_DESC (message, "A message string passed to the module");

static int
dev_open (struct inode *inode, struct file *file)
{
  printk (KERN_INFO "Device opened\n");
  message_ptr = message; // Reset the message pointer when device is opened
  return 0;
}

static int
dev_release (struct inode *inode, struct file *file)
{
  printk (KERN_INFO "Device closed\n");
  return 0;
}

static ssize_t
dev_read (struct file *file, char *buffer, size_t len, loff_t *offset)
{
  int bytes_read = 0;

  // >>> 实现读入设备字符。

  return bytes_read;
}

static struct file_operations fops
    = { .open = dev_open, .read = dev_read, .release = dev_release };

static int __init
chardev_init (void)
{
  major = register_chrdev (0, DEVICE_NAME, &fops);
  if (major < 0)
    {
      printk (KERN_ALERT "Failed to register a major number\n");
      return major;
    }
  printk (KERN_INFO "Registered a major number %d\n", major);
  printk (KERN_INFO "Message passed to module: %s\n", message);
  return 0;
}

static void __exit
chardev_exit (void)
{
  unregister_chrdev (major, DEVICE_NAME);
  printk (KERN_INFO "Unregistered the major number %d\n", major);
}

module_init (chardev_init);
module_exit (chardev_exit);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("Your Name");
MODULE_DESCRIPTION (
    "Virtual Character Device Module with Parameterized Input");
