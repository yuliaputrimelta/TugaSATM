#include <stdio.h>
#include <stdlib.h>
void banner()
{
    int pilih;
    printf("==================================\n");
    printf("===========  BANK TEKNIK ELEKTRO  ===========\n");
    printf("==================================\n\n");
}


int main() {
    // Inisialisasi PIN awal
    int pin = 21604;
    // Inisialisasi saldo awal
    float balance = 5000000;
    // Inisialisasi variabel-variabel lain yang dibutuhkan
    int choice, login_attempt = 0;
    int transfer_account_number;
    float saldo_awal, saldo_akhir, jumlah_transfer;
    char nama_bank[50], nomor_rekening[50], kode_bank_tujuan[10];
    float transfer_amount, top_up_dana, top_up_gopay,top_up_shoppe_pay,top_up_pln,top_up_ovo,withdrawal_amount;

    // Loop while untuk mengulang login hingga maksimal 3 kali percobaan
    while (login_attempt < 3) {
        // Meminta pengguna memasukkan PIN
        int input_pin;
        printf("Silahkan Masukan PIN: ");
        scanf("%d", &input_pin);
        
        // Jika PIN benar, tampilkan menu opsi
        if (input_pin == pin) {
            printf("\nAnda Berhasil Masuk!\n");

            while (1) {
                printf("\nMenu ATM\n");
                printf("1. Lihat Saldo\n");
                printf("2. Isi Saldo\n");
                printf("3. Penarikan\n");
                printf("4. Transfer\n");
                printf("5. Top Up\n");
                printf("6. Keluar\n");
                printf("Silahkan Masukan Transaksi Yang Akan Dilakukan: ");
                scanf("%d", &choice);
                
                // Switch case untuk setiap opsi pada menu
                switch (choice) {
                    case 1:
                        printf("Jummlah Saldo Anda Saat Ini: %.2f\n", balance);
                        break;
                    case 2:
                        printf("Masukan Nominal Uang: ");
                        float deposit_amount;
                        scanf("%f", &deposit_amount);
                        balance += deposit_amount;
                        printf("Saldo Berhasil Ditambah. Saldo Anda Saat Ini: %.2f\n", balance);
                        break;
                    case 3:
                        printf("Masukan Nominal Uang Yang Akan Diambil: ");
                        scanf("%f", &withdrawal_amount);
                        if (withdrawal_amount > balance) {
                            printf("Maaf Saldo Tidak Cukup.\n");
                        } else {
                            balance -= withdrawal_amount;
                            printf("Penarikan Berhasil. Saldo Anda Saat Ini: %.2f\n", balance);
                        }
                        break;
                    case 4:
                         printf("Nama bank tujuan: ");
                         scanf("%s", &nama_bank);
                         printf("Nomor rekening tujuan: ");
                         scanf("%s", &nomor_rekening);
    
                         printf("kode bank tujuan: ");
                         scanf("%s", &kode_bank_tujuan);
    
                         printf("jumlah yang ingin akan di transfer: ");
                         scanf("%f", &jumlah_transfer);
                         printf("Masukan PIN: ");
                         scanf("%d", &pin);
                         printf("Transfer Berhasil. Jumlah Saldo Anda Saat Ini: %.2f\n", balance -=top_up_dana);
    
    if (jumlah_transfer > balance) {
        printf("Saldo Anda Tidak Cukup Untuk Mentransfer Dengan Nominal %f", jumlah_transfer);
    } else {
        saldo_akhir = balance - jumlah_transfer;
        printf("Transfer dengan nominal %f berhasil dilakukan ke rekening %s pada bank %s dengan kode bank tujuan %s.\n", jumlah_transfer, nomor_rekening, nama_bank, kode_bank_tujuan);
        printf("Jumlah saldo anda saat ini adalah %f", saldo_akhir);
    }
                        break;
                    case 5:
                        printf("Menu Top Up\n");
                        printf("1. Top up Dana\n");
                        printf("2. Top up Gopay\n");
                        printf("3. Top Up ShoppePay\n");
                        printf("4. Top Up Ovo\n");
                        printf("Masukan Pilihan Anda: ");
                        int top_up_choice;
                        scanf("%d", &top_up_choice);
                        switch (top_up_choice) {
                            case 1:
                                printf("Masukan Nominal Isi Ulang: ");
                                scanf("%f", &top_up_dana);
                                printf("Masukan PIN: ");
                                scanf("%d", &pin);
                                printf("Isi Ulang Berhasil. Saldo Saat Ini Adalah: %.2f\n", balance -=top_up_dana);
                                break;
                            case 2:
                                printf("Masukan Nominal Isi Ulang: ");
                                scanf("%f", &top_up_gopay);
                                printf("Masukan PIN: ");
                                scanf("%d", &pin);
                                printf("Isi Ulang Berhasil. Saldo Saat Ini Adalah: %.2f", balance -= top_up_gopay);
                                break;
                            case 3:
                                printf("Masukan Nominal Isi Ulang: ");
                                scanf("%f", &top_up_shoppe_pay);
                                printf("Masukan PIN: ");
                                scanf("%d", &pin);
                                printf("Isi Ulang Berhasil, Saldo Saat Ini Adalah: %.2f", balance -= top_up_shoppe_pay);
                                printf("Isi Ulang Berhasil, Sisa Saldo Anda Saat Ini Adalah: %.2f\n", balance);
                                 break;
                            case 4:
                                printf("Masukan Nominal Akan Di Isi Ulang: ");
                                scanf("%f", &top_up_ovo);
                                printf("Masukan PIN: ");
                                scanf("%d", &pin);
                                printf("Isi Ulang Berhasil. Saldo Saat Ini Adalah: %.2f", balance -= top_up_pln);
                              
                            break;
                            default:
                                printf("\nPilihan Tidak Tersedia.\n");
                                break;
                        }
                        break;
                    case 6:
                        // Keluar dari menu dan kembali ke menu login
                        printf("Logout Berhasil.\n");
                        login_attempt = 3;
                        break;
                    default:
                        printf("\nPilihan Tidak Tersedia.\n");
                        break;
                }
            }
        } else {
            // Jika PIN salah, tampilkan pesan error dan tingkatkan jumlah percobaan
            printf("PIN salah. Silakan coba lagi..\n");
            login_attempt++;
        }
    }
    // Jika sudah 3 kali percobaan login dan masih gagal, keluar dari program
    if (login_attempt == 3) {
        printf("Anda Salah Memasukan Pin Lebih dari 3 Kali, silahkan menghubungi admin.\n");
    }
    return 0;
}
