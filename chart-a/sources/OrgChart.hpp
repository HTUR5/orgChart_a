#pragma once
#include <iostream>
#include <string>
#include <vector>


using namespace std;


namespace ariel {

    class OrgChart{ 
        
        private:

            struct Node {            
                string _name;
                std::vector<Node*> _childs;

                Node(const string &name, Node* n) {
                    _name = name;
                }
            };
        
            Node *root;
        
        public:
        
            OrgChart();
            friend ostream& operator<<(ostream& out, const OrgChart &organization);
            OrgChart& add_root(string name);
            OrgChart& add_sub(string dad_name, string son_name);

        
        class Iterator{
            
            private:
                int count;
                Node *pointerNode;
            
            public:
                
                Iterator() {
                this->count = 0;
                this->pointerNode = NULL;
                }

                const Iterator operator++(int) {
                    Iterator it = *this;
                    return it;
                }

                bool operator!=(const Iterator& it) {
                    return false;
                }

                string operator*() {
                    return "str";
                }

                Iterator& operator++() {
                    return *this;
                }

                string* operator->() {
                    string *str;
                    return str;
                }

            };
            
            Iterator begin_reverse_order();
            Iterator reverse_order();
            Iterator begin_level_order();
            Iterator end_level_order();
            Iterator begin_preorder();
            Iterator end_preorder();
            int* begin();
            int* end();
    };
   
}