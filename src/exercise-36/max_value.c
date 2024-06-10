#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/string.h>

#define MAX_ARR_SIZE 100

static char *input_str = NULL;
module_param (input_str, charp, S_IRUGO);
MODULE_PARM_DESC (input_str, "A comma-separated string of integers");

static int arr[MAX_ARR_SIZE];
static int arr_size = 0;

static int
parse_input (const char *input, int *arr, int *size)
{
  char *str, *token;
  char *saveptr;
  int value, count = 0;

  // Allocate memory for the input string copy
  str = kstrdup (input, GFP_KERNEL);
  if (!str)
    return -ENOMEM;

  // Split the input string by commas using strsep
  while ((token = strsep (&str, ",")) != NULL)
    {
      if (kstrtoint (token, 10, &value) == 0)
        {
          if (count < MAX_ARR_SIZE)
            {
              arr[count++] = value;
            }
          else
            {
              break;
            }
        }
    }

  *size = count;

  // Free the allocated memory
  kfree (str);

  return 0;
}

static int
max_value (int arr[], int size)
{
  int max = arr[0];

  // >>> 在这里实现最大值查找。

  return max;
}

static int __init
max_init (void)
{
  int max;

  if (!input_str)
    {
      printk (KERN_ERR "No input string provided\n");
      return -EINVAL;
    }

  if (parse_input (input_str, arr, &arr_size) != 0)
    {
      printk (KERN_ERR "Failed to parse input string\n");
      return -EINVAL;
    }

  if (arr_size == 0)
    {
      printk (KERN_ERR "Array is empty\n");
      return -EINVAL;
    }

  max = max_value (arr, arr_size);
  printk (KERN_INFO "Maximum value in the array: %d\n", max);

  return 0;
}

static void __exit
max_exit (void)
{
  printk (KERN_INFO "Module unloaded\n");
}

module_init (max_init);
module_exit (max_exit);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("Your Name");
MODULE_DESCRIPTION ("Array Maximum Value Module");
