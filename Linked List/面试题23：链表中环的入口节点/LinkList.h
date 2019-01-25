typedef struct BNode
{
	int data;
	struct BNode *next;
}BNode,*BTlist;

void InitList(BTlist *plist);

bool Insert_head(BTlist *plist,int val);

bool Insert_tail(BTlist *plist,int val);

bool Insert_pos(BTlist *plist,int pos,int val);

BNode *Search(BTlist plist,int key);

BNode *Search_pri(BTlist plist,int key);

bool Delete(BTlist *plist,int key);

void Destroy(BTlist plist);

void Show(BTlist plist);

int GetLength(BTlist plist);

bool IsEmpty(BTlist plist);