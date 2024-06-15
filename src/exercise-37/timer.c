#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/timer.h>

static struct timer_list my_timer;

static void
my_timer_callback (struct timer_list *timer)
{
  printk (KERN_INFO "Timer callback function called [%lu].\n", jiffies);
  mod_timer (&my_timer, jiffies + msecs_to_jiffies (5000));
}

static int __init
timer_init (void)
{
  printk (KERN_INFO "Module loaded\n");

  // >>> 在这里实现计数器
  timer_setup(&my_timer, my_timer_callback, 0);
  // >>> Start timer after 5000 milliseconds (5 seconds)
  mod_timer(&my_timer, jiffies + msecs_to_jiffies(5000));

  return 0;
}

static void __exit
timer_exit (void)
{
  del_timer (&my_timer);
  printk (KERN_INFO "Module unloaded\n");
}

module_init (timer_init);
module_exit (timer_exit);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("Your Name");
MODULE_DESCRIPTION ("Module with timer");
