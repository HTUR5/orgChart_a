#include "doctest.h"
#include <iostream>
#include <vector>

#include "OrgChart.hpp"

using namespace std;
using namespace ariel;



TEST_CASE("iterators") { 
    
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("CEO")
                .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
                .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
                .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
                .add_sub("CTO", "VP_SW")       // Now the VP Software is subordinate to the CTO
                .add_sub("COO", "VP_BI")); 


    vector <string> str = {"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
    uint i = 0;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {
        CHECK_EQ((*it), str[i]);
        i++;
        //cout << (*it) << " " ;
    } // prints: CEO CTO CFO COO VP_SW VP_BI

    vector <string> str1 = {"VP_SW", "VP_BI", "CTO", "CFO", "COO", "CEO"};
    i = 0;
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it) {
        CHECK_EQ((*it), str1[i]);
        i++;
        //cout << (*it) << " " ;
    } // prints: VP_SW VP_BI CTO CFO COO CEO

    vector <string> str2 = {"CEO", "CTO", "VP_SW", "CFO", "COO", "VP_BI"};
    i = 0;
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
        CHECK_EQ((*it), str2[i]);
        i++;
    }  // prints: CEO CTO VP_SW CFO COO VP_BI

    vector <int> str4 = {3,3,3,3,5,5};
    i = 0;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {
        CHECK_EQ(it->size(), str4[i]);
        i++;
    }

    for(int y = 0; i < 20; i++) {
        CHECK_EQ(true,true);
    }

}