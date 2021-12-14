#include "Node.h"
#include <string>
using namespace std;
class circle_list
{
    public:
        void insert(string name,int val); 
        void del_next();       
        void go_next();        
        void go_first();       
        void go_last();
        void right();
        void left();
        void show();    
        int  size();           
		void sort_alphabet(); 
        circle_list();
        ~circle_list();
        void sort_ASC();
        void sort_DESC();
    private:
        Node*  head;          
        Node*  position;       
        int count;         
};

