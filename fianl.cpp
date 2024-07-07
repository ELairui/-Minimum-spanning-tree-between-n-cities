#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 100
#define INF 99999

//边的结构体
struct Edge{
    int u;
    int v;
    int weight;
};

int parent[MAX];     //并查集数组，帮助查找集合的根
int graph[MAX][MAX];  //邻接矩阵
string cities[MAX];    //城市名称数组

//并查集找根节点的函数
int find(int i){
    while (parent[i] != i)
        i=parent[i];
    return i;
}//如果父节点不是自己，则继续往上找，直到找到相等为止
 //父节点为自己的节点就是根节点

//并查集合并两个集合的函数
void unionSets(int x,int y){
    int xRoot=find(x);
    int yRoot=find(y);
    if (xRoot!=yRoot){
        parent[yRoot] =xRoot;  //将一个根节点的父节点设置为另一个，从而合并
    }
}

//Kruskal算法实现最小生成树
void kruskalMst(int n,Edge edges[],int E){
    for(int i=0;i<n;i++){
        parent[i]=i;  //初始化并查集，每个点的根都设为自己
    }
    
    //对边按权重排序
    sort(edges,edges+E,[](Edge a,Edge b){
        return a.weight <b.weight;  //用了sort和一个lambda来排序edges
    });

    int mstWeight=0; //mst权重初始化为0
    cout << endl;
    cout <<endl;
    cout << "最小生成树的边:" <<endl;

    for (int i=0,e=0;i<E && e<n-1;i++){   //i是指已经判断到第几条边，e是指mst已经有几条边
        int u=find(edges[i].u);
        int v=find(edges[i].v);
        if (u !=v){           //如果根不相等，说明可以连接且不形成环（根相等，说明已经连接，若再连该边，就形成环）
            cout <<cities[edges[i].u] << " --> " <<cities[edges[i].v]<<"=="<<edges->weight<<endl;mstWeight +=edges[i].weight; //mst权重
            unionSets(u,v);        //合并
            e++;  //增加已选择的边数
        }
    }
    cout << endl;
    cout <<endl;
    cout << "最小生成树的总权值：" <<mstWeight <<endl; //输出最小生成树权值
}

void displayMatrix(int n) {
    cout <<endl;
    cout <<endl;
    cout << "邻接矩阵:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
               if (graph[i][j] == INF) {
                cout << "  INF"; // 保持"INF"前有足够空间以对齐
            } else {
                if (graph[i][j] < 10) {
                    cout << "    " << graph[i][j]; // 一位数
                } else if (graph[i][j] < 100) {
                    cout << "   " << graph[i][j]; // 两位数
                } else if (graph[i][j] < 1000) {
                    cout << "  " << graph[i][j]; // 三位数
                } else {
                    cout << " " << graph[i][j]; // 四位数
                }
            }
            cout << " ";  // 在数字或INF后添加一个空格来分隔列
        }
        cout << endl;
    }
}

//处理预定义城市数据的函数
void predefinedCities(){
    cout << "选择城市区域：1 华北地区，2 华南地区，或 3 西北地区（输入序号）：\n";
    int choice, n = 6, E;
    cin >> choice;

    Edge edges[MAX];

    // 初始化邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    switch (choice) {
        case 1:
            cities[0] = "北京"; cities[1] = "天津"; cities[2] = "石家庄"; cities[3] = "太原";
            cities[4] = "秦皇岛"; cities[5] = "呼和浩特";
            edges[0] = {0, 1, 120}; edges[1] = {0, 2, 295}; edges[2] = {0, 3, 500};
            edges[3] = {1, 3, 550}; edges[4] = {2, 3, 330}; edges[5] = {1, 4, 70};
            edges[6] = {2, 4, 140}; edges[7] = {4, 5, 190}; edges[8] = {3, 5, 220};
            edges[9] = {1, 5, 300};
            E = 10;
            cout << "地区: 华北地区" << endl;
            cout << "0北京，1天津，2石家庄，3太原，4秦皇岛，5呼和浩特" << endl;
            break;
        case 2:
            cities[0] = "广州"; cities[1] = "深圳"; cities[2] = "珠海"; cities[3] = "佛山";
            cities[4] = "东莞"; cities[5] = "中山";
            edges[0] = {0, 1, 140}; edges[1] = {0, 2, 120}; edges[2] = {1, 2, 90};
            edges[3] = {1, 3, 150}; edges[4] = {2, 3, 85}; edges[5] = {0, 3, 30};
            edges[6] = {1, 4, 60}; edges[7] = {2, 4, 40}; edges[8] = {3, 4, 50};
            edges[9] = {4, 5, 70};
            E = 10;
            cout << "地区: 华南地区" << endl;
            cout << "0广州，1深圳，2珠海，3佛山，4东莞，5中山" << endl;
            break;
        case 3:
            cities[0] = "西安"; cities[1] = "兰州"; cities[2] = "银川"; cities[3] = "乌鲁木齐";
            cities[4] = "敦煌"; cities[5] = "张掖";
            edges[0] = {0, 1, 570}; edges[1] = {0, 2, 660}; edges[2] = {1, 2, 310};
            edges[3] = {1, 3, 1770}; edges[4] = {2, 3, 1460}; edges[5] = {0, 4, 780};
            edges[6] = {1, 4, 590}; edges[7] = {2, 4, 690}; edges[8] = {3, 4, 1270};
            edges[9] = {3, 5, 980};
            E = 10;
            cout << "地区: 西北地区" << endl;
            cout << "0西安，1兰州，2银川，3乌鲁木齐，4敦煌，5张掖" << endl;
            break;
        default:
            cout << "无效的选择!" << endl;
            return;
    }
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        graph[u][v] = weight;
        graph[v][u] = weight;  // 将边转化为邻接矩阵
    }
    cout << "请选择 1 最小生成树， 2 邻接矩阵（填写序号）:" <<endl;
    int userDecision;
    cin >> userDecision;
    if (userDecision==1)
        kruskalMst(n, edges, E);
    else if(userDecision==2)
        displayMatrix(n);
     else{ cout << "无效的选择！" <<endl;}
}

void custom(){
    int n,E=0;
    cout << "输入城市数量：";
    cin >> n;

    for(int i=0;i<n;i++){
        cout << "输入城市"<< i+1 <<"的名称：";
        cin >>cities[i];
    }
    
    //初始化邻接矩阵
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i==j) graph[i][j]=0;
            else graph[i][j] =INF;
        }
    }
    cout << "请输入城市间的距离，使用-1表示没有直接路径：";
    for(int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            cout << "输入从" <<cities[i]<<"到"<<cities[j]<< " 的距离: ";
            int dist;
            cin >> dist;
            if (dist != -1){
                graph[i][j]=dist;
                graph[j][i]=dist;
            }
        }
    }
    Edge edges[MAX];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (graph[i][j] != INF) {
                    edges[E++] = {i, j, graph[i][j]};
                }
            }
        }
    kruskalMst(n, edges, E);
    displayMatrix(n);
}

int main(){
    bool continueRunning = true;
    while (continueRunning)
    {
        cout << "选择选项：1 选择已有城市，2 自定义城市" <<endl;
        int operation;
        cin >>operation;
        if(operation ==1){
            predefinedCities();
        }
        else if(operation==2) {
            custom();
        }
        else{ cout << "无效的选择！" <<endl;}
    cout << "要继续操作吗？输入'no'退出，其他任何输入将继续。" << endl;
        string userDecision;
        cin >> userDecision;
        if (userDecision == "no") {
            continueRunning = false;
        }
    }
    return 0;    
}