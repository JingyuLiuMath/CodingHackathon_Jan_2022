bool visited[MaxVnum];
void DFS(Graph G, int v)
{
    visited[v] = true; //��V��ʼ���ʣ�flag��
    printf("%d", v);    //��ӡ��V
    for (int j = 0; j < G.vexnum; j++)
        if (G.arcs[v][j] == 1 && visited[j] == false) //������Ի��Vδ���ʹ����ڽӵ�
            DFS(G, j); //�ݹ���ã�������нڵ㶼�����ʹ����ͻ��ݣ������ٵ��������DFS
}

void DFSTraverse(Graph G) {
    for (int v = 0; v < G.vexnum; v++)
        visited[v] = false; //�տ�ʼ��û�б����ʹ�

    for (int v = 0; v < G.vexnum; ++v)
        if (visited[v] == false) //��û�з��ʹ��ĵ�һ��Ԫ��������ͼ
            DFS(G, v);