/*********************************
**  Last modified : 2014.7.28   **
*********************************/

#ifndef QUIZMODULE_H_INCLUDED
#define QUIZMODULE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Question{
    private:
        int order_number;
        string description;
        string option_1, option_2, option_3, option_4;
        int answer;
    public:
        Question();
        Question(int order_num, string desc, string opt1, string opt2, string opt3, string opt4, int ans);
        ~Question();
        void setOrderNumber(int order_num);
        void setDescription(string desc);
        void setOption(string opt1, string opt2, string opt3, string opt4);
        void setAnswer(int ans);
        string getDescription();
        string getOption_1();
        string getOption_2();
        string getOption_3();
        string getOption_4();
        int getAnswer();
        void showQuestion();//print the question on the console
};

class Quiz{
    private:
        /*
            ifs                 : read quiz file
            quiz_file_name      : decide which quiz file to open
            quiz_total_number   : the total amounts of questions
        */
        ifstream ifs;
        string quiz_file_name;
        int quiz_total_number;
        int question_index;
        vector<int> random_num;
        vector<class Question> question;
    public:
        /*
            --Main tool--
            void showQuestionMessage()       : print question
            bool checkAns(int)               : check for answer
            void nextQuestion();             : change question
        */
        Quiz();
        Quiz(int boss_number, int n);//read quiz file, store questions and generate radom question order
        ~Quiz();
        void setQuizFile(int boss_number);
        void setQuizFileName(int boss_number);
        void setInputFileStream(int boss_number);
        void readQuizData();
        void setRandomNumber();
        void setQuestionIndex(int index);
        void setQuizTotalNumber(int total_num);
        int getRandomQuestionNumber();
        void nextQuestion();//change question_index
        string getQuizFileName();
        int getQuizTotalNumber();
        int getQuestionIndex();
        bool checkAns(int player_ans);
        void showAnswerResult(bool bingo);
        void showQuestionMessage();

};
#endif // QUIZMODULE_H_INCLUDED
