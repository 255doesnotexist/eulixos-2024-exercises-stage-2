#include <linux/fs.h>
#include <linux/module.h>
#include <linux/uaccess.h>

#define FILE_NAME "/tmp/testfile"

static struct file *file_ptr = NULL;

static int __init
fileop_init (void)
{
  // >>> 实现文件访问操作。
  //
  // if true
  //     printk(KERN_INFO "File operation successful\n")
  //   printk(KERN_ALERT "Failed to open file\n")

  file_ptr = filp_open(FILE_NAME, O_RDWR | O_CREAT, 0644);
  if (IS_ERR(file_ptr)) {
      printk(KERN_ALERT "Failed to open file\n");
      file_ptr = NULL;
      return PTR_ERR(file_ptr);
  } else {
      printk(KERN_INFO "File operation successful\n");
  }

  return 0;
}

static void __exit
fileop_exit (void)
{
  if (file_ptr)
    {
      filp_close (file_ptr, NULL);
      printk (KERN_INFO "File closed\n");
    }
}

module_init (fileop_init);
module_exit (fileop_exit);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("Your Name");
MODULE_DESCRIPTION ("Simple File Operation Module");
