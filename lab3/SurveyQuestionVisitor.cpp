#include "SurveyQuestionVisitor.h"
#include <fstream>
#include "ChoiceQuestion.h"
#include "FreeQuestion.h"
#include "RangeQuestion.h"
#include "YesNoQuestion.h"

SurveyQuestionBinarySerializationVisitor::SurveyQuestionBinarySerializationVisitor(string _file)
{
	file = _file;
}

SurveyQuestionBinarySerializationVisitor::~SurveyQuestionBinarySerializationVisitor()
{
}

void clearOrCreateFile(string _file)
{
	ofstream fout(_file);
	fout.close();
}

void SurveyQuestionBinarySerializationVisitor::visit(ChoiceQuestion & ref)
{
	ofstream fout(file, std::ios::binary|std::ios::app);
	fout << "Choice\n";
	fout.write(reinterpret_cast<char*>(&ref), sizeof(ChoiceQuestion));
	fout.close();

	cout << "bin choise\n";
}

void SurveyQuestionBinarySerializationVisitor::visit(FreeQuestion & ref)
{
	ofstream fout(file, std::ios::binary | std::ios::app);
	fout << "Free\n";
	fout.write(reinterpret_cast<char*>(&ref), sizeof(FreeQuestion));
	fout.close();

	cout << "bin free\n";
}

void SurveyQuestionBinarySerializationVisitor::visit(RangeQuestion & ref)
{
	ofstream fout(file, std::ios::binary | std::ios::app);
	fout << "Range\n";
	fout.write(reinterpret_cast<char*>(&ref), sizeof(RangeQuestion));
	fout.close();

	cout << "bin range\n";
}

void SurveyQuestionBinarySerializationVisitor::visit(YesNoQuestion & ref)
{
	ofstream fout(file, std::ios::binary | std::ios::app);
	fout << "YesNo\n";
	fout.write(reinterpret_cast<char*>(&ref), sizeof(YesNoQuestion));
	fout.close();

	cout << "bin yesNo\n";
}

list<SurveyQuestion*> SurveyQuestionBinarySerializationVisitor::getQuestions()
{
	list <SurveyQuestion*> result;
	
	ifstream fin(file,std::ios::binary);
	//
	return result;
}

void SurveyQuestionTextDumpVisitor::visit(ChoiceQuestion & ref)
{
	ofstream fout(file, ios_base::app);//ios_base::binary
	fout << "Choice\n";
	fout << ref.getQuestion() << endl;
	fout << ref.getAnswerCount() << endl;
	for (int i = 0; i < ref.getAnswerCount(); i++)
	{
		fout << ref.getAnswer(i) << endl;
	}
}

void SurveyQuestionTextDumpVisitor::visit(FreeQuestion & ref)
{
	ofstream fout(file, ios_base::app);
	fout << "Free\n";
	fout << ref.getQuestion() << endl;
}

void SurveyQuestionTextDumpVisitor::visit(RangeQuestion & ref)
{
	ofstream fout(file, ios_base::app);
	fout << "Range\n";
	//QuestionToTxtFile(fout, &ref);
	fout << ref.getQuestion() << endl;
	fout << ref.getStart() << endl;
	fout << ref.getFinish() << endl;
	fout << ref.getStep() << endl;
}

void SurveyQuestionTextDumpVisitor::visit(YesNoQuestion & ref)
{
	ofstream fout(file, ios_base::app);
	fout << "YesNo\n";
	fout << ref.getQuestion() << endl;
}

list<SurveyQuestion*> SurveyQuestionTextDumpVisitor::getQuestions()
{
	list <SurveyQuestion *> result;
	
	ifstream fin(file);
	while (!fin.eof())
	{
		string s;
		getline(fin, s);
		
		if (s == "YesNo")
		{
			string q;
			getline(fin, q);
			YesNoQuestion *question = new YesNoQuestion(q);
			result.push_back(question);
		}

		if (s == "Free")
		{
			string q;
			getline(fin, q);
			FreeQuestion* question = new FreeQuestion(q);
			result.push_back(question);
		}

		if (s == "Choice")
		{
			string q;
			getline(fin, q);
			int size=0;
			fin >> size;
			vector<string> var;
			for (int i = 0; i <= size; i++)
			{
				string s;
				getline(fin, s);
				if (s.length()>0)
					var.push_back(s);
			}
			ChoiceQuestion* question = new ChoiceQuestion(q,var);
			result.push_back(question);
		}

		if (s == "Range")
		{
			string q;
			getline(fin, q);
			int start=0, fini=0, step=0;
			fin >> start;
			fin >> fini;
			fin >> step;
			RangeQuestion * question = new RangeQuestion(start, fini, step, q);
			result.push_back(question);
		}
	}
	
	return result;
}

SurveyQuestionTextDumpVisitor::SurveyQuestionTextDumpVisitor(string _file)
{
	file = _file;
	clearOrCreateFile(file);
}

SurveyQuestionTextDumpVisitor::~SurveyQuestionTextDumpVisitor()
{
}

void printQuestion(SurveyQuestion * ref)
{
	cout << ref->getQuestion() << "\t" << ref->getAnswerCount() << "\t";
	for (int i = 0; i < ref->getAnswerCount(); i++)
	{
		cout << i << " " << ref->getAnswer(i) << "\t";
	}
	cout << '\n';
}

SurveyQuestionConsoleWriterVisitor::~SurveyQuestionConsoleWriterVisitor()
{
}
void SurveyQuestionConsoleWriterVisitor::visit(ChoiceQuestion & ref)
{
	listQ.push_back(&ref);
	printQuestion(&ref);
}

void SurveyQuestionConsoleWriterVisitor::visit(FreeQuestion & ref)
{
	listQ.push_back(&ref);
	printQuestion(&ref);
}

void SurveyQuestionConsoleWriterVisitor::visit(RangeQuestion & ref)
{
	listQ.push_back(&ref);
	printQuestion(&ref);
}

void SurveyQuestionConsoleWriterVisitor::visit(YesNoQuestion & ref)
{
	listQ.push_back(&ref);
	printQuestion(&ref);
}

list<SurveyQuestion*> SurveyQuestionConsoleWriterVisitor::getQuestions()
{
	return listQ;
}
