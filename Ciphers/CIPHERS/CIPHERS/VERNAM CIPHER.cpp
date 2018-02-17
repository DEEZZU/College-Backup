//
//  VERNAM CIPHER.cpp
//  CIPHERS
//
//  Created by DEEPTI SHARMA on 22/11/17.
//  Copyright © 2017 DEEPTI SHARMA. All rights reserved.
//  Encryption
//  The the plaintext(P) and key(K) are added modulo 26.
//  Ei = (Pi + Ki) mod 26
//
//  Decryption
//  Di = (Ei - Ki + 26) mod 26
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string encryption(string,string);
string decryption(string,string);
string generate(string,string);

int  main(){
    
    string samplePlainText="PLAINTEXT";
    string sampleKey="KEY";
    string sampleCipherText;
    
    cout << "\n VERNAM CIPHER " ;
    //    cout << "\n ASSUMPTION : The case of the plaintext and key is the same , that is either both are upper case or both are lower case " ;
    cout << "\n\n Sample Test ";
    cout << "\n\n PLAINTEXT : " << samplePlainText ;
    cout << "\n KEY : " << sampleKey ;
    cout << "\n\n ENCRYPTING... " << endl ;
    cout << "\n CIPHER TEXT : " << encryption(samplePlainText,generate(samplePlainText,sampleKey));
    cout << "\n\n DECRYPTING... " << endl ;
    cout << "\n PLAINTEXT/ORIGINAL TEXT : " << decryption(encryption(samplePlainText,generate(samplePlainText,sampleKey)), generate(samplePlainText,sampleKey)) ;
    
    
    string plainText, key, cipherText;
    string repeatedKey;
    
    cout << "\n\n ENTER THE PLAINTEXT : ";
    cin >> plainText ;
    
    cout << "\n ENTER THE KEY : " ;
    cin >> key ;
    
    repeatedKey = generate(plainText,key);
    //    cout << "repeatedKey : " << repeatedKey ;
    cipherText = encryption(plainText,repeatedKey) ;
    cout << " CIPHERTEXT GENERATED FORM THE PLAINTEXT : " << cipherText << endl ;
    plainText = decryption(cipherText,repeatedKey) ;
    cout << " PLAINTEXT GENERATED FROM THE CIPHERTEXT : " << plainText << endl ;
    
    
    return 0;
}

string generate(string P,string K){
    
    long PLen, Klen ;
    int i,j;
    string keyWord;
    
    j=0;
    PLen = P.size() ;
    Klen = K.size() ;
    
    for ( i=0 ; i < PLen ; i++ ){
        
        keyWord.push_back(K[j++]);
        //      keyWord[i] = K[j++];
        j=j%Klen;
    }
    
    return keyWord;
}

string encryption(string P, string K){
    
    string cipherText;
    int i ;
    int x;
    
    for ( i=0 ; i<P.size() ; i++ ){
        
        x=P[i];
        if(isupper(P[i])){
            x-='A';
        }
        else{
            x-='a';
        }
        
        if(isupper(K[i])){
            K[i]-='A';
        }
        else{
            K[i]-='a';
        }
        
        x=(x^K[i]);
        
        if(isupper(P[i])){
            x+='A';
        }
        else{
            x+='a';
        }

        cipherText.push_back(x);
//        cout << (int)x << " ";
    }
    
    return cipherText;
}

string decryption(string C , string K){
    
    string plainText;
    int i;
    int x;
    
    for ( i=0 ; i<C.size() ; i++ ){
        
        x=C[i];
        if(isupper(C[i])){
            x-='A';
        }
        else{
            x-='a';
        }
        
        if(isupper(K[i])){
            K[i]-='A';
        }
        else{
            K[i]-='a';
        }
        
        x = (x^K[i]);
        
        if(isupper(C[i])){
            x+='A';
        }
        else{
            x+='a';
        }
        
        plainText.push_back(x);
    }
    
    return plainText;
}



