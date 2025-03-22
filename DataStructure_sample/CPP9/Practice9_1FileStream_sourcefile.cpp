//Practice 9 #1 file stream
//실습 9 1번 csv파일 입출력 코드


#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;


//csv 파일을 읽어오는 함수
void ReadCsv(std::string FileName, std::vector<std::vector<std::string>>& Data)
{
    //file의 이름을 parameter로 받아서 파일을 연다.
    std::ifstream ifs;

    ifs.open(FileName);
    if (!ifs.is_open()) return;

    //file의 내용을 한 줄씩 읽어오기 위해 문자열, 및 구분자(,) 선언 및 초기화
    std::string LineString = "";
    std::string Delimeter = ",";
    
    //getline을 이용해서 한 줄씩 읽어오고 쉼표를 찾아서 그 nFindPos에 대입한다.
    //읽은 line 속의 값을 vector에 push_back한다.
    //','의 수가 nPos와 같을 경우에는 nFIndPos가 LineString의 길이와 같고, rowdata의 값을 vector에 push_back한다
    while (getline(ifs, LineString))
    {
        std::vector<std::string> RowData;
        unsigned int nPos = 0, nFindPos;
        do {
            nFindPos = LineString.find(Delimeter, nPos);
            if (nFindPos == std::string::npos) nFindPos = LineString.length();

            RowData.push_back(LineString.substr(nPos, nFindPos - nPos));
            nPos = nFindPos + 1;
        } while (nFindPos < LineString.length());
        Data.push_back(RowData);
    }


    //file의 내용을 전부 읽은 후에는 close를 이용해서 파일을 닫는다.
    ifs.close();
}

int main()
{
    vector<vector<string>> list;
    ReadCsv("diabetes.csv", list);
    for (int i = 0; i < list.size(); i++)
    {
        cout << "data[" << i << "]";
        for (int j = 0; j < list[i].size(); j++)
        {
            std::cout << list[i][j] << " ";
        }
        std::cout << endl;
    }
}