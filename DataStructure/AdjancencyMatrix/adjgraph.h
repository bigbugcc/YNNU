#define MAX_VERTEX_NUM  20
typedef enum { DG, DN, UDG, UDN } GraphKind;//ͼ������
/*����߽��ṹ*/
typedef struct ArcNode
{
	int adjvex;//�û�ָ��Ķ���λ��
	struct ArcNode* nextarc;//ָ����һ������ָ��
	int  weight;
}ArcNode;

/*�������ṹ*/
typedef  struct VertexNode
{
	char data;//��������Ϊ�ַ���
	ArcNode* firstarc;//ָ��߽���ָ��
}VertexNode;

/*����ͼ���ڽӱ�*/
typedef struct
{
	VertexNode vertex[MAX_VERTEX_NUM];//��ͷ�������
	int vexnum, arcnum;//ͼ�Ķ������ͱߣ�������
//	GraghKind  kind;
}AdjList;

