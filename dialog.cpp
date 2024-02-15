#include "dialog.h"
#include "ui_dialog.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <list>
using namespace std;
#include <iterator>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// (1) //// Считывание из файла нейронов в массив: ////////////////////////////////////////////////////////////////////////////////////////////
    try
    {
        std::ifstream f("/home/viktor/my_projects_qt_2/Funkciya_podachi_signalov_na_vhod/neyroni_i_signal.txt");
        if(!f)
        {
            std::cerr << "ERROR: Cannot open '/home/viktor/my_projects_qt_2/Funkciya_podachi_signalov_na_vhod/neyroni_i_signal.txt'!" << std::endl;
            exit(1);
        }
        std::string line;
        // QString line;
        //  template<class T>
        std::list<unsigned long long//int
                  > my_list_neyronov = { //12, 5, 10
            };
        // std::list mylist;   
        while (std::getline(f,line))
        {
            my_list_neyronov.push_back(
                std::atoll // строку в unsigned long long
                //  atoi
                ( line.c_str() )  );  // atoi( line.c_str() )   
            // std::cout << my_list.back() << std::endl;
            // вывод в текстэдит
         //   ui->textEdit->append (QString::number(my_list_neyronov.back()));
        }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////         
    }
    catch(const std::exception& ex)
    {
        std::cerr << "Exception: '" << ex.what() << "'!" << std::endl;
        exit(1);
    }
    //  exit(0);
//////////////////////////////// (1) ///// Конец считывания из файла нейронов в массив. ////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////// (2) //// Считывание из файла синапсов в массив: ////////////////////////////////////////////////////////////////////////////////////////////
    try
    {
        std::ifstream f("/home/viktor/my_projects_qt_2/build-zapolnenie_sinapsov_sluchajnymi_nachalnymi_soprotivleniyami_2-Desktop_Qt_5_12_12_GCC_64bit-Debug/sinapsi.txt");
        if(!f)
        {
            std::cerr << "ERROR: Cannot open '/home/viktor/my_projects_qt_2/build-zapolnenie_sinapsov_sluchajnymi_nachalnymi_soprotivleniyami_2-Desktop_Qt_5_12_12_GCC_64bit-Debug/sinapsi.txt'!" << std::endl;
            exit(1);
        }
        std::string line;
        // QString line;
        //  template<class T>
        std::list<unsigned long long//int
                  > my_list_sinapsov = { //12, 5, 10
            };
        // std::list mylist;   
        while (std::getline(f,line))
        {
            my_list_sinapsov.push_back(
                std::atoll // строку в unsigned long long
                //  atoi
                ( line.c_str() )  );  // atoi( line.c_str() )   
            // std::cout << my_list.back() << std::endl;
            // вывод в текстэдит
        //   ui->textEdit_2->append (QString::number(my_list_sinapsov.back()));
        }
        
        
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////         
    }
    catch(const std::exception& ex)
    {
        std::cerr << "Exception: '" << ex.what() << "'!" << std::endl;
        exit(1);
    }
    //  exit(0);
    ///////////////////////////////// (2) ////// Конец считывания из файла синапсов в массив. ////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
/// 
/// 
//////////////////////////////////////////// (3) Функция решения funktsiya_resheniya ///////////////////////////////////////////////////////////////////////////////////////////////////
 std::list<int> numbers{ 1, 2, 3, 4, 5 };
    // перебор в цикле
    for (int n : numbers)
        std::cout << n << "\n";
    std::cout << std::endl;
    // перебор с помощью итераторов
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
    {
        std::cout << *iter << "\t";
    }
    std::cout << std::endl;
 // https://metanit.com/cpp/tutorial/7.6.php   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
//auto it = std::list(numbers.begin(), index);
    std::list<int>::const_iterator it = numbers.begin();
     // std::list<int>::iterator it = numbers.begin();
    std::advance(it, 7);
    // Теперь *it относится к нужному вам элементу.
    std::cout << "2)" << *it << "\n";
        std::cout << std::endl;
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::vector<int> v = { 1, 2, 3, 4, 5 }; 
    std::cout << v[4] << '\n';    // UB if v has less than 4 elements
    std::cout << v.at(4) << '\n'; // throws if v has less than 4 elements    

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//    for (int var = 101; var < 201; ++var) // это диапазон нейронов 
//    {
//        // это для одного 101 нейрона:
//        for (int index_neyrona=1,index_sinapsa = 1;index_neyrona < 201, index_sinapsa<10101 ; ++index_neyrona,index_sinapsa=index_sinapsa+100)
//        // где то тут ошибка за диапазон выходит
//        {
//            // тут можно костыль поставить проверка что Synaps::Peremennaia_Soprotivlenie_Sinapsa[index_sinapsa] не 0
//            if (Synaps::Peremennaia_Soprotivlenie_Sinapsa[index_sinapsa]==0)
//            {
//                Synaps::Peremennaia_Soprotivlenie_Sinapsa[index_sinapsa]=1;
//            }
//            Neiron::Peremennaia_Zariad_Neirona[var]=Neiron::Peremennaia_Zariad_Neirona[var]+
//                                                      (Neiron::Peremennaia_Zariad_Neirona[index_neyrona]/ Synaps::Peremennaia_Soprotivlenie_Sinapsa[index_sinapsa]);
//            // вот здесь генерируется исключение деление на 0
//        }
        
//    }
    // нейроны второго ряда посчитаны    
    
    
    
    
    
    
    
    
    
    
}

Dialog::~Dialog()
{
    delete ui;
}

