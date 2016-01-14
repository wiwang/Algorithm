
struct foo
{
    int a;
    char b;
    long c;
}

DEFINE_SPINLOCK(foo_mutex);

struct foo *gbl_foo;

void dosomething(int a, char b, long c)
{

    return;
}

void foo_read(void)
{
    struct foo *fp = gbl_foo;
    
    return;
}
