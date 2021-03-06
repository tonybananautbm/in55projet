#include "p.h"

P::P()
{

}

void P::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    stGet st = getShorts(src->GetText());
    m_Indices = st.s;
    m_Count = st.count;
}

stGet P::getShorts(string values){
    stGet st_Get;
    istrstream iss(values.c_str());
    vector<unsigned short> *tokens = new vector<unsigned short>();
    string token;
    while(getline(iss, token, ' ')){
        //cout << "str indice i " << token;
        if(!token.empty()) tokens->push_back((unsigned short)atoi(token.c_str()));
        //cout << "  indice i " << (unsigned short)atoi(token.c_str())<<endl;
    }
    st_Get.s = tokens->data();
    st_Get.count = tokens->size();
    return st_Get;
}
