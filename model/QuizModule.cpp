/*********************************
**  Last modified : 2014.7.28   **
*********************************/

#include "QuizModule.h"
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

Quiz::Quiz(int boss_number, int n){
    this->setQuizFile(boss_number);
    this->setRandomNumber();
}

void Quiz::setQuizFile(int boss_number){
    //First, open the corresponding file to set ifs
    this->setInputFileStream(boss_number);

    //Second, set ifs successfully, start read file and store data
    this->readQuizData();
}

void Quiz::setInputFileStream(int boss_number){
    //...UNDER DEVELOPING...
    //find boss name using character module
    this->quiz_file_name = "Q915.txt";
    this->ifs.open("Q915.txt", ifstream::in);
    if(ifs.fail()){
        cout << "Error! No such questions about the boss..." << endl;
        //ifs.open("general_quiz.txt");
    }
    /*
        setQuizFileName(boss_number);
    */
}

void Quiz::setQuizFileName(int boss_number){
    //...UNDER DEVELOPING...
    //find boss name using character module
    string file_name;
    string boss_name;

    //.........BOSS NAME............

    file_name = "Q" + boss_name + ".txt";
    this->quiz_file_name = file_name;
}

void Quiz::readQuizData(){
    int number_of_questions;
    string desc, opt1, opt2, opt3, opt4;
    int ans;
    string nl;//store new line

    //read first line, the total number of questions
    this->ifs >> number_of_questions;
    this->setQuizTotalNumber(number_of_questions);

    getline(ifs, nl);//store new line character
    //use for loop to add the Question into question(vector<class Question>)
    for(int i=0; i < this->quiz_total_number ; i++){
        getline(ifs, desc);
        getline(ifs, opt1);
        getline(ifs, opt2);
        getline(ifs, opt3);
        getline(ifs, opt4);
        this->ifs >> ans;
        getline(ifs, nl);//store new line character

        this->question.push_back(Question(i, desc, opt1, opt2, opt3, opt4, ans));
    }

    this->ifs.close();
}

void Quiz::setQuizTotalNumber(int total_num){
    this->quiz_total_number = total_num;
}

void Quiz::setRandomNumber(){
    //Because quiz_total_number is set before this function,
    //so we can use this variable
    int vector_size = quiz_total_number;
    int number[vector_size];
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
        cout << "回答錯誤..." << endl;
}

void Quiz::showQuestionMessage(){
    int number = this->question_index;
    Question q = this->question.at(number);

    q.showQuestion();
}
