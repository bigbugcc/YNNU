#define MAX_VERTEX_NUM  20
typedef enum { DG, DN, UDG, UDN } GraphKind;//图的种类
/*定义边结点结构*/
typedef struct ArcNode
{
	int adjvex;//该弧指向的顶点位置
	struct ArcNode* nextarc;//指向下一条弧的指针
	int  weight;
}ArcNode;

/*定义表结点结构*/
typedef  struct VertexNode
{
	char data;//顶点类型为字符型
	ArcNode* firstarc;//指向边结点的指针
}VertexNode;

/*定义图的邻接表*/
typedef struct
{
	VertexNode vertex[MAX_VERTEX_NUM];//表头结点数组
	int vexnum, arcnum;//图的顶点数和边（弧）数
//	GraghKind  kind;
}AdjList;

