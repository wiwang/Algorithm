
#define MAXSIZE 20

typedef int KeyType;
typedef int InfoType;
typedef struct
{
    KeyType key;
    InfoType otherinfo;
}RedType;

#define    InvalidMethod 0
#define    InsertionSortMethod 1
#define    ShellSortMethod 2
#define    QuickSortMethod 3
#define    BubbleSortMethod 4
#define    SelectionSortMethod 5
#define    MergeSortMethod 6
#define    HeapSortMethod 7
