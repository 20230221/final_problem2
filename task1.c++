# include <iostream>
# include <cmath>
# include <string>
# include <cctype>
# include <limits>
using namespace std;
string text ;
// Function to delete anything other than letters
string ignoreNunAlpha(string text)
{
    string newText;
    for (int i=0;i<text.size();i++){
        if (isalpha(text[i])){
            newText+=text[i];
        }
        else{
            continue;
        }
    }
    return newText;
}
// Function of converting lowercase letters to uppercase
string convertToUpper(string text){
    string newtext;
    for (int i=0;i<text.size();i++){
        if (islower(text[i])){
         newtext+=char(toupper(text[i]));
        }
        else{
            newtext+=text[i];
        }

    }
    return newtext;
}
// Function to avoid incorrect number of columns  Encryption
/*int validitionColums(){
    int colums;
    while (true){
        cout<<"====================="<<endl;
        cout << "enter the key";
        cin >> colums;
        string text1=ignoreNunAlpha(convertToUpper(text));
        if(colums>1 && colums<=int(0.5*text1.size())){
            break;
        }
        else{
            cout <<"invalid number\n";
            continue;
        }
    }
    return colums;
}*/
int validationColumns() {
    int  columns;
    while (true) {
        cout << "=====================" << endl;
        cout << "Enter the key: ";

        cin >> columns;

        if (cin.fail() ) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a valid number " << endl;
            continue;
        }
        string text1 = ignoreNunAlpha(convertToUpper(text));
        if (columns>=1 && columns <= int(0.5 * text1.size())) {
            break;
        } else {
            cout << "Invalid number. Please enter a valid number less than or equal to half the size of the text." << endl;
            continue;
        }
    }
    return columns;
}
void Encryption(string text){
    int count =0;
    double rows;
    count = text.size() ;
    int colums= validationColumns();
    //calculate the number of rows
    rows=double(count)/colums;
    //Avoid getting a number that is less than the number of letters in the text
    rows= ceil(rows);
    //create a matrix
    char matrix[int(rows)][colums] ;
    int m = 0 ;
    //Enter text into the matrix
    for (int i=0;i<rows;i++){
        for(int j=0;j<colums;j++){
            if (m<text.size()){
                matrix[i][j]=text[m];
                m++;
            }
            else 
            {
                //If the number of letters in the word has expired and the number of rows is not full
                matrix[i][j] = 'X';
            }

        }
    }
    //Obtain the desired spiral shape
    string result;
    int left=0,bottom=int(rows)-1;
    int top=0,right=colums-1;
    while (top<=bottom&&left<=right){
        for (int i=top;i<=bottom;i++){
            result+=matrix[i][right];
        }
        right--;
        if (top<=bottom){
            for (int i=right;i>=left;i--){
                result+=matrix[bottom][i];
            }
            bottom--;
        }
        if(left<=right){
            for (int i=bottom;i>=top;i--){
                result+=matrix[i][left];
            }
            left++;
        }
        for (int i=left;i<=right;i++){
            result+=matrix[top][i];
        }
        top++;
    }
    cout<<"====================="<<endl;
    cout <<"Encryption result  :"<<result<<endl;
    cout<<"====================="<<endl;
}
void Decryption(string text){
    int count =0;
    double rows;
    count = text.size() ;
    int colums= validationColumns();
    //calculate the number of rows
    rows=double(count)/colums;
    //Avoid getting a number that is less than the number of letters in the text
    rows= ceil(rows);
    //create a matrix
    char matrix[int(rows)][colums];
    int count1=0;
    // Fill the matrix
    string result;
    int left=0,bottom=int(rows)-1;
    int top=0,right=colums-1;
    while (top<=bottom&&left<=right){
        for (int i=top;i<=bottom;i++){
            matrix[i][right]=text[count1];
            count1++;
        }
        right--;
        if (top<=bottom){
            for (int i=right;i>=left;i--){
                matrix[bottom][i]=text[count1];
                count1++;
            }
            bottom--;
        }
        if(left<=right){
            for (int i=bottom;i>=top;i--){
                matrix[i][left]=text[count1];
                count1++;
            }
            left++;
        }
        for (int i=left;i<=right;i++){
            matrix[top][i]=text[count1];
            count1++;
        }
        top++;
        if (count1==text.size()){
            break;
        }
    }
    //Assemble the array so that the word is obtained before encryption
    for (int i=0;i<rows;i++){
        for(int j=0;j<colums;j++){
            result+=matrix[i][j];
        }
    }
    cout<<"====================="<<endl;
    cout <<"Decryption result  :"<<result<<endl;
    cout<<"====================="<<endl;
}

int main()
{
    cout<<"enter the text please"<<endl;
    cout<<"====================="<<endl;
    getline(cin,text);
    Encryption(ignoreNunAlpha(convertToUpper(text)));
    cout<<"enter the text please"<<endl;
    cout<<"====================="<<endl;
    cin.ignore();
    getline(cin,text);
    Decryption(ignoreNunAlpha(convertToUpper(text)));
    return 0;
}






