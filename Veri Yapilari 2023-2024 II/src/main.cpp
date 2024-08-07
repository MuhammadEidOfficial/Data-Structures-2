#include "Avl.hpp"
#include "LinkedList.hpp"
#include "FileManager.hpp"
#include "StringManager.hpp"

LinkedList* init_list(string path);
char get_ascii_char(int toplam);

int main(){
    LinkedList* list = init_list("Veri.txt");
    list->run();
    return 0;
}

LinkedList* init_list(string path){
    FileManager* fm = new FileManager("Veri.txt");
    StringManager* sm = new StringManager();
    string* allLines = fm->get_all_lines();
    LinkedList* list = new LinkedList();
    int linesCount = fm->get_line_count();
    for(int i = 0 ;i < linesCount ; i++){
        Stack* stk = new Stack();
        Avl* avl = new Avl();
        int slicesCount = sm->get_slices_count(allLines[i]," ");
        string* line = sm->split(slicesCount,allLines[i]," ");
        for(int j = 0 ; j < slicesCount ; j++){
            int num = stoi(line[j]);
            avl->Add(num);
        }
        avl->push_leafs(stk);
        avl->findToplam();
        int toplam = avl->get_toplam();
        char charAscii = get_ascii_char(toplam);
        list->add(*avl,stk,charAscii);
        delete[] line;
    }
    delete fm;
    delete sm;
    delete[] allLines;

    return list;
}
char get_ascii_char(int toplam){
    char ascii = toplam%(90-65 + 1) + 65;
    return ascii;
}