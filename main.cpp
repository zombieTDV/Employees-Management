#include <iostream>
using namespace std;
#include<string>
#include<cstring>
struct NV
{
    string idNV;
    string hoTenNV;
    string ngaySinh;
    string emailNV;
    string diaChiNV;
    int sdtNV;
    int soNgayCong;
    float luongNgay;
    float thucLinh;
    void tinhThucLinh(){
        thucLinh = soNgayCong * luongNgay;
    }
};
struct NODE
{
    NV data;
    NODE* pNext;
};
typedef NODE* list;
NODE* create_node(NV x)
{
    NODE* p = new NODE;
    if( p == NULL)
    return NULL;
    p -> data = x;
    p -> pNext = NULL;
}
void create_list (list &l)
{
    l = NULL;
}
