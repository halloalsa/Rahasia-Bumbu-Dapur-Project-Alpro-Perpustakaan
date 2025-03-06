//membuat program mengenai soritng dan searching data dalam sistem pengelolaan buku di perpustakaan.

#include <iostream>
#include <string>
using namespace std;

struct Buku
{
    string judul;
    string pengarang;
    string penerbit;
    int nomor_rak;
    int tahun_terbit;
};

struct Perpustakaan 
{
    Buku buku[100];
    int jml_buku = 0;

    void AddBooks(string judul, string pengarang, string penerbit, int nomor_rak, int tahun_terbit) 
    {
        buku[jml_buku].judul = judul;
        buku[jml_buku].pengarang = pengarang;
        buku[jml_buku].penerbit = penerbit;
        buku[jml_buku].nomor_rak = nomor_rak;
        buku[jml_buku].tahun_terbit = tahun_terbit;
        jml_buku++;
    }

    void DisplayBooks() 
    {
        if (jml_buku == 0) 
        {
            cout << "There are no books at all in the library." << endl;
            return;
        }
            cout << "=====================================================\n";
            cout << "|       List of Books in Linkon Library Center      |\n";
            cout << "=====================================================\n";
        for (int i = 0; i < jml_buku; i++) 
        {
            cout << "Book Title  : " << buku[i].judul << endl;
            cout << "Author : " << buku[i].pengarang << endl;
            cout << "Publisher : " << buku[i].penerbit << endl;
            cout << "Shelf Number : " << buku[i].nomor_rak << endl;
            cout << "Publication Year : " << buku[i].tahun_terbit << endl;
            cout << endl;
        }
    }

    void FindBooks(string judul) 
    {
        for (int i = 0; i < jml_buku; i++) 
        {
            if (buku[i].judul == judul) 
            {
                cout << "=====================================================\n";
                cout << "|                  Book found! >_<                  |\n";
                cout << "=====================================================\n";
                cout << "Book Title : " << buku[i].judul << endl;
                cout << "Author : " << buku[i].pengarang << endl;
                cout << "Publisher : " << buku[i].penerbit << endl;
                cout << "Shelf Number : " << buku[i].nomor_rak << endl;
                cout << "Publication Year : " << buku[i].tahun_terbit << endl;
                return;
            }
        }
                cout << "====================================================================\n";
                cout << "|                      Book not found T__T                         |\n";
                cout << "====================================================================\n";
                cout << "Book with the title " << judul << " is not available in the library." << endl;
                cout << "Please check the title of the book you entered." << endl;
}

    void DeleteBooks(string judul) 
    {
        for (int i = 0; i < jml_buku; i++) 
        {
            if (buku[i].judul == judul) 
            {
                cout << "==================================================================\n";
                cout << "|                      Book Deleted! >_<                         |\n";
                cout << "==================================================================\n";
                cout << "Book with the title " << judul << " has been successfully deleted." << endl;
                for (int j = i; j < jml_buku; j++) 
                {
                    buku[j] = buku[j + 1];
                }
                jml_buku--;
                return;
            }
        }
                cout << "====================================================================\n";
                cout << "|                      Book not found T__T                         |\n";
                cout << "====================================================================\n";
                cout << "Book with the title " << judul << " is not available in the library." << endl;
                cout << "Please check the title of the book you entered." << endl;
    }

    void BorrowBooks(string judul) 
    {
        for (int i = 0; i < jml_buku; i++) 
        {
            if (buku[i].judul == judul) 
            {
                cout << "=====================================================\n";
                cout << "|                  Borrowing Books!                 |\n";
                cout << "=====================================================\n";
                cout << "Book Title : " << buku[i].judul << endl;
                cout << "Author : " << buku[i].pengarang << endl;
                cout << "Publisher : " << buku[i].penerbit << endl;
                cout << "Shelf Number : " << buku[i].nomor_rak << endl;
                cout << "Publication Year : " << buku[i].tahun_terbit << endl;
                cout << "The book has been successfully borrowed." << endl;
                return;
            }
        }
                cout << "====================================================================\n";
                cout << "|                      Book not found T__T                         |\n";
                cout << "====================================================================\n";
                cout << "Book with the title " << judul << " is not available in the library." << endl;
                cout << "Please check the title of the book you entered." << endl;
    }

    void ReturnBooks(string judul) 
    {
        for (int i = 0; i < jml_buku; i++) 
        {
            if (buku[i].judul == judul) 
            {
                cout << "=====================================================\n";
                cout << "|                  Returning Books!                 |\n";
                cout << "=====================================================\n";
                cout << "Book Title : " << buku[i].judul << endl;
                cout << "Author : " << buku[i].pengarang << endl;
                cout << "Publisher : " << buku[i].penerbit << endl;
                cout << "Shelf Number : " << buku[i].nomor_rak << endl;
                cout << "Publication Year : " << buku[i].tahun_terbit << endl;
                cout << "The book has been successfully returned." << endl;
                return;
            }
        }
                cout << "====================================================================\n";
                cout << "|                      Book not found T__T                         |\n";
                cout << "====================================================================\n";
                cout << "Book with the title " << judul << " is not available in the library." << endl;
                cout << "Please check the title of the book you entered." << endl;
    }

    // Fungsi Bubble Sort
    void BubbleSort() 
    {
        int n = jml_buku;
        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n - 1 - i; j++) 
            {
                if (buku[j].judul > buku[j + 1].judul) 
                {
                    swap(buku[j], buku[j + 1]);
                }
            }
        }
        cout << "Books have been successfully sorted using Bubble Sort!" << endl;
    }

    // Fungsi Insertion Sort
    void InsertionSort() 
    {
        int n = jml_buku;
        for (int i = 1; i < n; i++) 
        {
            Buku key = buku[i];
            int j = i - 1;
            while (j >= 0 && buku[j].judul > key.judul) 
            {
                buku[j + 1] = buku[j];
                j--;
            }
            buku[j + 1] = key;
        }
        cout << "Books have been successfully sorted using Insertion Sort!" << endl;
    }

    // Fungsi Selection Sort
    void SelectionSort() 
    {
        int n = jml_buku;
        for (int i = 0; i < n - 1; i++) 
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) 
            {
                if (buku[j].judul < buku[minIndex].judul) 
                {
                    minIndex = j;
                }
            }
            swap(buku[i], buku[minIndex]);
        }
        cout << "Books have been successfully sorted using Selection Sort!" << endl;
    }

    // Fungsi Shell Sort
    void ShellSort() 
    {
        int n = jml_buku;
        for (int gap = n / 2; gap > 0; gap /= 2) 
        {
            for (int i = gap; i < n; i++) 
            {
                Buku temp = buku[i];
                int j;
                for (j = i; j >= gap && buku[j - gap].judul > temp.judul; j -= gap) 
                {
                    buku[j] = buku[j - gap];
                }
                buku[j] = temp;
            }
        }
        cout << "Books have been successfully sorted using Shell Sort!" << endl;
    }

    // Fungsi Quick Sort
    void QuickSort() 
    {
        QuickSortHelper(0, jml_buku - 1);
        cout << "Books have been successfully sorted using Quick Sort!" << endl;
    }

    void QuickSortHelper(int low, int high) 
    {
        if (low < high) 
        {
            int pi = Partition(low, high);
            QuickSortHelper(low, pi - 1);
            QuickSortHelper(pi + 1, high);
        }
    }

    int Partition(int low, int high) 
    {
        string pivot = buku[high].judul;
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) 
        {
            if (buku[j].judul < pivot) 
            {
                i++;
                swap(buku[i], buku[j]);
            }
        }
        swap(buku[i + 1], buku[high]);
        return i + 1;
    }

    // Fungsi Merge Sort
    void MergeSort() 
    {
        MergeSortHelper(0, jml_buku - 1);
        cout << "Books have been successfully sorted using Merge Sort!" << endl;
    }

    void MergeSortHelper(int l, int r) 
    {
        if (l < r) 
        {
            int m = l + (r - l) / 2;
            MergeSortHelper(l, m);
            MergeSortHelper(m + 1, r);
            Merge(l, m, r);
        }
    }

    void Merge(int l, int m, int r) 
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        Buku L[n1];
        Buku R[n2];

        for (int i = 0; i < n1; i++) 
        {
            L[i] = buku[l + i];
        }
        for (int i = 0; i < n2; i++) 
        {
            R[i] = buku[m + 1 + i];
        }

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) 
        {
            if (L[i].judul <= R[j].judul) 
            {
                buku[k] = L[i];
                i++;
            } 
            else 
            {
                buku[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) 
        {
            buku[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) 
        {
            buku[k] = R[j];
            j++;
            k++;
        }
    }

    void SortBooks() 
    {
        int pilihan;
        cout << "===========================================================\n";
        cout << "|          Sorting Books in Linkon Library Center         |\n";
        cout << "===========================================================\n";
        cout << "| 1. Bubble Sort                                          |" << endl;
        cout << "| 2. Insertion Sort                                       |" << endl;
        cout << "| 3. Selection Sort                                       |" << endl;
        cout << "| 4. Shell Sort                                           |" << endl;
        cout << "| 5. Quick Sort                                           |" << endl;
        cout << "| 6. Merge Sort                                           |" << endl;
        cout << "| 7. Back to Main Menu                                    |" << endl;
        cout << "===========================================================\n";
        cout << "Enter your choice : ";
        cin >> pilihan;
        cin.ignore(); // to ignore newline character after entering integer

        switch (pilihan) 
        {
            case 1:
                BubbleSort();
                break;
            case 2:
                InsertionSort();
                break;
            case 3:
                SelectionSort();
                break;
            case 4:
                ShellSort();
                break;
            case 5:
                QuickSort();
                break;
            case 6:
                MergeSort();
                break;
            case 7:
                cout << "Back to Main Menu... Thank you!" << endl;
                return;
            default:
                cout << "Invalid choice! Please enter a number between 1-7." << endl;
        }
    }


};

int main() 
{
    Perpustakaan perpustakaan;
    int pilihan;
    string judul, pengarang, penerbit;
    int nomor_rak, tahun_terbit;

    while (true) 
    {
        cout << "===========================================================\n";
        cout << "|         Linkon Library Center Management System         |\n";
        cout << "===========================================================\n";
        cout << "| 1. Add Book                                             |" << endl;
        cout << "| 2. Display Books                                        |" << endl;
        cout << "| 3. Find Book by Title                                   |" << endl;
        cout << "| 4. Delete Book by Title                                 |" << endl;
        cout << "| 5. Borrow Book by Title                                 |" << endl;
        cout << "| 6. Return Book by Title                                 |" << endl;
        cout << "| 7. Sort Books                                           |" << endl;
        cout << "| 8. Exit                                                 |" << endl;
        cout << "===========================================================\n";
        cout << "Enter your choice : ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) 
        {
            case 1:
                cout << "Enter the title of the book : ";
                getline(cin, judul);
                cout << "Enter the author of the book : ";
                getline(cin, pengarang);
                cout << "Enter the publisher of the book : ";
                getline(cin, penerbit);
                cout << "Enter the shelf number of the book : ";
                cin >> nomor_rak;
                cout << "Enter the publication year of the book : ";
                cin >> tahun_terbit;
                cin.ignore(); 
                for (int i = 0; i < perpustakaan.jml_buku; i++) 
                {
                    if (judul == perpustakaan.buku[i].judul) 
                    {
                        cout << "The title has been successfully added." << endl;
                        return 0;
                    }
                }

                perpustakaan.AddBooks(judul, pengarang, penerbit, nomor_rak, tahun_terbit);
                break;
            case 2:
                perpustakaan.DisplayBooks();
                break;
            case 3:
                cout << "Enter the title of the book : ";
                getline(cin, judul);
                perpustakaan.FindBooks(judul);
                break;
            case 4:
                cout << "Enter the title of the book : ";
                getline(cin, judul);
                perpustakaan.DeleteBooks(judul);
                break;
            case 5:
                cout << "Enter the title of the book : ";
                getline(cin, judul);    
                perpustakaan.BorrowBooks(judul);
                break;
            case 6:
                cout << "Enter the title of the book : ";
                getline(cin, judul);
                perpustakaan.ReturnBooks(judul);
                break;
            case 7:
                perpustakaan.SortBooks();
                break;
            case 8:
                cout << "Exiting the program... Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1-8." << endl;
        }
    }

    return 0;
}


