#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef struct
{
    float x, y;
} Diem;

typedef struct
{
    int n;
    Diem A[100];
} D_Diem;

void NhapDayDiem(D_Diem &D)
{
    //Nhap
    printf("\nNhap so diem n = ");
    scanf("%d", &D.n);

    for (int i = 1; i <= D.n; i++)
    {
        printf("Nhap toa do diem thu A%d : ", i);
        scanf("%.2f%.2f", &D.A[i].x, &D.A[i].y);
    }
}

void XuatDayDiem(D_Diem D)
{
    //Xuat day diem ra man hinh
    printf("\nDay diem vua nhap la :");
    for (int i = 1; i <= D.n; i++)
        printf("\nToa do diem thu A%d la (%.2f,%.2f) ", i, D.A[i].x, D.A[i].y);
}

float DoDaiDGK(D_Diem D)
{
    //Tinh do dai duong gap khuc
    printf("\n\nCau 1");
    float s = 0;
    for (int i = 1; i < D.n; i++)
    {
        float u = D.A[i + 1].x - D.A[i].x;
        float v = D.A[i + 1].y - D.A[i].y;
        s = s + sqrt(u * u + v * v);
    }
    return s;
}

void TimNhungDiemXaOxNhat(D_Diem D)
{
    int i;
    //Tim cac diem xa truc hoanh nhat
    printf("\n\nCau 2");
    float max = fabs(D.A[1].y);
    for (i = 2; i <= D.n; i++)
        if (max < fabs(D.A[i].y))
            max = fabs(D.A[i].y);
    printf("\nKhoang cach xa trung hoanh nhat la %f gom cac diem : \n", max);
    for (i = 1; i <= D.n; i++)
        if (fabs(D.A[i].y) == max)
            printf("\nToa do A%d la (%f,%f) ", i, D.A[i].x, D.A[i].y);
}

int DoanCatOy(D_Diem D)
{
    int i, j;
    //Liet ke cac doan cat truc tung
    printf("\n\nCau 3");
    int dem = 0;
    for (i = 1; i <= D.n; i++)
        for (j = i + 1; j <= D.n; j++)
            if ((D.A[i].x * D.A[j].x <= 0) && (fabs(D.A[i].x) + fabs(D.A[j].x) > 0))
            {
                dem++;
                printf("\nDoan A%dA%d cat truc tung ", i, j);
            }
    return dem;
}

int main()
{
    int n, i, j;
    D_Diem D;
    NhapDayDiem(D);
    XuatDayDiem(D);
    printf("\n\nDo dai duong gap khuc la %.2f", DoDaiDGK(D));
    TimNhungDiemXaOxNhat(D);
    printf("\nCo tat ca %d doan cat truc tung", DoanCatOy(D));
    getch();
    return 1;
}