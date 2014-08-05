/*********************************
**  Last modified : 2014.8.5   **
*********************************/

#include "QuizModule.h"
#include "function.h"
#define QUESTION_MAX_LENGTH 300
#define OPTION_MAX_LENGTH 150

Question::Question(int order_num, string desc, string opt1, string opt2, string opt3, string opt4, int ans){
    this->setOrderNumber(order_num);
    this->setDescription(desc);
    this->setOption(opt1, opt2, opt3, opt4);
    this->setAnswer(ans);
}

void Question::setOrderNumber(int order_num){
    this->order_number = order_num;
}

void Question::setDescription(string desc){
    this->description = desc;
}

void Question::setOption(string opt1, string opt2, string opt3, string opt4){
    this->option_1 = opt1;
    this->option_2 = opt2;
    this->option_3 = opt3;
    this->option_4 = opt4;
}

void Question::setAnswer(int ans){
    this->answer = ans;
}

void Question::showQuestion(){
    //print question message on the console
    cout << "[Q]" <<this->description << endl;
    cout << "\t1." << this->option_1 << endl;
    cout << "\t2." << this->option_2 << endl;
    cout << "\t3." << this->option_3 << endl;
    cout << "\t4." << this->option_4 << endl;
    cout << "請於10秒內作答!\n[Ans]:";
}

string Question::getDescription(){
    return this->description;
}

string Question::getOption_1(){
    return this->option_1;
}

string Question::getOption_2(){
    return this->option_2;
}

string Question::getOption_3(){
    return this->option_3;
}

string Question::getOption_4(){
    return this->option_4;
}
int Question::getAnswer(){
    return this->answer;
}

Question::~Question(){

}

Quiz::Quiz(string boss_name, int n){
    this->setQuizFile(boss_name);
    this->setRandomNumber();
}

void Quiz::setQuizFile(string boss_name){
    //First, open the corresponding file to set ss
    if(this->setInputFileStream(boss_name))
        //Second, set ss successfully, start read file and store data
        this->readQuizData();
    else
        cout << "Error! No such questions about the boss..." << endl;
}

bool Quiz::setInputFileStream(string boss_name){
    //find boss name using character module
    this->quiz_file_name = "data/Q" + boss_name + ".txt";

    if(!read_whole_file_to_stringstream(this->ss, this->quiz_file_name.c_str()))
        return false;

    return true;
}

void Quiz::readQuizData(){
    int number_of_questions;
    string desc, opt1, opt2, opt3, opt4;
    int ans;
    char nl;//store new line

    //read first line, the total number of questions
    this->ss >> number_of_questions;
    this->setQuizTotalNumber(number_of_questions);

    ss.get(nl);//store new line character
    //use for loop to add the Question into question(vector<class Question>)
    for(int i=0; i < this->quiz_total_number ; i++){
        getline(ss, desc);
        getline(ss, opt1);
        getline(ss, opt2);
        getline(ss, opt3);
        getline(ss, opt4);
        this->ss >> ans;
        ss.get(nl);//store new line character

        this->question.push_back(Question(i, desc, opt1, opt2, opt3, opt4, ans));
    }
}

void Quiz::setQuizTotalNumber(int total_num){
    this->quiz_total_number = total_num;
}

void Quiz::setRandomNumber(){
    //Because quiz_total_number is set before this function,
    //so we can use this variable
    int vector_size = quiz_total_number;
    int* number = new int[vector_size];
    int n;//random number

    for(int i=0; i < vector_size; i++)
        number[i] = i;

    srand( time(NULL) );
    //Knuth-Fisher-Yates shuffle algorithm
    //to create a new question order
    for(int i=vector_size-1; i > 0; i--){
        n = rand()%(i+1);
        swap(number[i], number[n]);
    }

    //Now the order is in random
    //set the question order
    for(int i=0; i < vector_size; i++)
        this->random_num.push_back(number[i]);

    //set up question number
    this->setQuestionIndex(this->getRandomQuestionNumber());

    delete [] number;
}

void Quiz::setQuestionIndex(int index){
    this->question_index = index;
}

int Quiz::getRandomQuestionNumber(){
    int num = this->random_num.back();
    this->random_num.pop_back();
    return num;
}

void Quiz::nextQuestion(){
    this->setQuestionIndex(this->getRandomQuestionNumber());
}

string Quiz::getQuizFileName(){
    return this->quiz_file_name;
}

int Quiz::getQuizTotalNumber(){
    return this->quiz_total_number;
}

int Quiz::getQuestionIndex(){
    return this->question_index;
}

bool Quiz::checkAns(int player_ans){
    bool result;
    int number = this->question_index;
    Question q = this->question.at(number);

    result = (q.getAnswer() == player_ans)?true:false;
    this->showAnswerResult(result);

    return result;
}

void Quiz::showAnswerResult(bool bingo){
    if(bingo)
        cout << "[O]回答正確!請選擇攻擊卡牌。" << endl;
    else
        cout << "[X]回答錯誤..." << endl;
}

void Quiz::showQuestionMessage(){
    int number = this->question_index;
    Question q = this->question.at(number);

    q.showQuestion();
}
