#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][20];
    char maSach[MAX][20];
    int soNgayMuon[MAX];
    int soLuong = 0;
    int luaChon;

    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH (LOGISTICS) ================\n");
        printf("1. Them moi phieu muon sach (Create)\n");
        printf("2. Hien thi danh sach phieu muon & Tien phat qua han (Read)\n");
        printf("3. Cap nhat so ngay muon sach (Update)\n");
        printf("4. Xac nhan tra sach / Xoa phieu muon (Delete)\n");
        printf("5. Thoat chuong trinh\n");
        printf("===========================================================================\n");
        printf("Lua chon cua ban (1-5): ");
        scanf("%d", &luaChon);
        while (getchar() != '\n'); 

        switch (luaChon) {
            case 1: {
                if (soLuong >= MAX) {
                    printf("Bo nho danh sach da day, khong the them moi!\n");
                    break;
                }
                
                printf("--- THEM MOI PHIEU MUON ---\n");
                char maTam[20];
                printf("Nhap ma phieu: ");
                scanf("%19s", maTam);
                while (getchar() != '\n');
                
                int biTrung = 0;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTam) == 0) {
                        biTrung = 1;
                        break;
                    }
                }
                
                if (biTrung == 1) {
                    printf("Ma phieu da ton tai trong he thong!\n");
                    break;
                }
                
                strcpy(maPhieu[soLuong], maTam);
                
                printf("Nhap ma sach: ");
                scanf("%19s", maSach[soLuong]);
                while (getchar() != '\n');
                
                do {
                    printf("Nhap so ngay muon: ");
                    scanf("%d", &soNgayMuon[soLuong]);
                    while (getchar() != '\n');
                    
                    if (soNgayMuon[soLuong] <= 0) {
                        printf("So ngay muon phai lon hon 0. Vui long nhap lai!\n");
                    }
                } while (soNgayMuon[soLuong] <= 0);
                
                soLuong++;
                printf("Them moi phieu muon thanh cong!\n");
                break;
            }
            
            case 2: {
                if (soLuong == 0) {
                    printf("Danh sach phieu muon hien dang rong!\n");
                } else {
                    printf("\n================================ DANH SACH PHIEU MUON ================================\n");
                    printf("%-5s %-15s %-15s %-10s %-15s %-20s\n", 
                           "STT", "MA PHIEU", "MA SACH", "SO NGAY", "TRANG THAI", "TIEN PHAT (VND)");
                    
                    for (int i = 0; i < soLuong; i++) {
                        long tienPhat = 0;
                        char trangThai[20];
                        
                        if (soNgayMuon[i] > 14) {
                            tienPhat = (soNgayMuon[i] - 14) * 5000;
                            strcpy(trangThai, "QUA HAN");
                        } else {
                            strcpy(trangThai, "DUNG HAN");
                        }
                        
                        printf("%-5d %-15s %-15s %-10d %-15s %-20ld\n", 
                               i + 1, maPhieu[i], maSach[i], soNgayMuon[i], trangThai, tienPhat);
                    }
                    printf("======================================================================================\n");
                }
                break;
            }
            
            case 3: {
                char maCapNhat[20];
                printf("Nhap ma phieu can cap nhat: ");
                scanf("%19s", maCapNhat);
                while (getchar() != '\n');
                
                int viTri = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maCapNhat) == 0) {
                        viTri = i;
                        break;
                    }
                }
                
                if (viTri == -1) {
                    printf("Khong tim thay ma phieu trong he thong!\n");
                } else {
                    printf("So ngay muon hien tai cua phieu %s la: %d\n", maCapNhat, soNgayMuon[viTri]);
                    printf("Nhap so ngay muon moi: ");
                    scanf("%d", &soNgayMuon[viTri]);
                    while (getchar() != '\n');
                    
                    printf("Cap nhat so ngay muon thanh cong!\n");
                }
                break;
            }
            
            case 4: {
                char maXoa[20];
                printf("Nhap ma phieu xac nhan tra/xoa: ");
                scanf("%19s", maXoa);
                while (getchar() != '\n');
                
                int viTri = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maXoa) == 0) {
                        viTri = i;
                        break;
                    }
                }
                
                if (viTri == -1) {
                    printf("Khong tim thay ma phieu can xoa!\n");
                } else {
                    for (int i = viTri; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(maSach[i], maSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                    }
                    soLuong--;
                    printf("Xac nhan tra sach va xoa phieu muon thanh cong!\n");
                }
                break;
            }
            
            case 5: {
                printf("Thoat chuong trinh. Chao tam biet!\n");
                break;
            }
            
            default: {
                printf("Lua chon khong hop le, vui long chon lai!\n");
                break;
            }
        }
    } while (luaChon != 5);

    return 0;
}