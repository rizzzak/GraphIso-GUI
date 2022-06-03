#include "FormSampleData.h"

double epsilon = 0.0001;
std::vector<std::vector<int>> graphBig, graphSmall;

std::vector<std::vector<int>> genGraphWithDensity(int n, double D)
{
    std::vector<std::vector<int>> newGraph;
    for (int i = 0; i < n; i++)
    {
        newGraph.push_back({});
        for (int j = 0; j < n; j++)
        {
            newGraph[i].push_back(0);
        }
    }
    double stepDPerEdge = 2. / (n * n - n);
    int edgesCnt;
    for (int k = 0; k < ((n * n - n) / 2.) + 1.0; k++)
    {
        if (k != 0)
        {
            if ((D > k * stepDPerEdge - epsilon - stepDPerEdge / 2) && (D <= k * stepDPerEdge + epsilon + stepDPerEdge / 2))
            {
                edgesCnt = k;
                break;
            }
        }
        else
        {
            if (D <= stepDPerEdge / 2)
            {
                edgesCnt = k;
                break;
            }
        }
    }
    int randomVertix1;
    int randomVertix2;
    for (int i = 0; i < edgesCnt; i++)
    {
        while (true)
        {
            randomVertix1 = rand() % n;
            randomVertix2 = rand() % n;
            if (randomVertix1 == randomVertix2)
                continue;
            if (newGraph[randomVertix1][randomVertix2] == 0)
            {
                newGraph[randomVertix1][randomVertix2] = 1;
                newGraph[randomVertix2][randomVertix1] = 1;
                break;
            }
        }
    }
    return newGraph;
}
//добавить пару графов в список
System::Void DotNet2::FormSampleData::button1_Click(System::Object^ sender, System::EventArgs^ e)
{

    //добавить строчку в список
    listBox1->Items->Add("ѕара "+ (listBox1->Items->Count + 1));
    this->selectedGraphPair = listBox1->Items->Count - 1;
    //подготовить матрицы к вводу пользовател€ : сохранить в выборку + очистить + оставить 1 €чейку
    if(this->graphBig->size() > 0)
        this->sampleGraphBig->push_back(*this->graphBig);
    else
        this->sampleGraphBig->push_back(std::vector<std::vector<int>>());
    if (this->graphSmall->size() > 0)
        this->sampleGraphSmall->push_back(*this->graphSmall);
    else
        this->sampleGraphSmall->push_back(std::vector<std::vector<int>>());
    this->graphBig = new std::vector<std::vector<int>>();
    this->graphSmall = new std::vector<std::vector<int>>();
    dataGridView1->Rows->Clear();
    dataGridView1->ColumnCount = 1;
    dataGridView1->RowCount = 2;
    dataGridView2->Rows->Clear();
    dataGridView2->ColumnCount = 1;
    dataGridView2->RowCount = 2;

}
//сохранить пару графов в выборку
System::Void DotNet2::FormSampleData::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    //считать номер редактируемую пару
    //перезаписать на него пару
    if (this->listBox1->SelectedIndex < 0) return;
    (*this->sampleGraphBig)[this->selectedGraphPair] = (*this->graphBig);
    (*this->sampleGraphSmall)[this->selectedGraphPair] = (*this->graphSmall);
    MessageBox::Show("Saved");

    //std::vector<int> graphRow;
    ////считывание матриц
    //int graphSize;
    //for (int i = 0; i < ; i++)
    //{
    //    dataGridView1->ColumnCount = sampleGraphBig->back().size();
    //    for (int j = 0; j < sampleGraphBig->back().size(); j++)
    //    {
    //        //dataGridView1->Column
    //    }
    //    dataGridView1->Rows->Add();
    //    for (int j = 0; j < sampleGraphBig->back()[i].size(); j++)
    //    {
    //        strBuf += sampleGraphBig->back()[i][j].ToString();
    //        String^ bufStr = sampleGraphBig->back()[i][j].ToString();
    //        dataGridView1->Rows[i]->Cells[j]->Value = bufStr;
    //    }
    //    strBuf += "\n";
    //}
    //добавление в вектор
    return System::Void();
}
//удалить пару графов из выборки
System::Void DotNet2::FormSampleData::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->sampleGraphBig->erase(this->sampleGraphBig->begin() + this->selectedGraphPair);
    this->sampleGraphSmall->erase(this->sampleGraphSmall->begin() + this->selectedGraphPair);
    this->listBox1->Items->RemoveAt(this->listBox1->SelectedIndex);
    this->listBox1->SelectedIndex = 0;
    return System::Void();
}
//генераци€ выборки с заданными параметрами
System::Void DotNet2::FormSampleData::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    //считывание введенных данных
    std::string graphASizeStr, graphBSizeStr, densityStr, sizeOfSampleStr;
    Convert_String_to_string(textBox1->Text->ToString(), graphASizeStr); //graph A - big graph
    Convert_String_to_string(textBox2->Text->ToString(), graphBSizeStr); //graph B - small graph
    Convert_String_to_string(textBox3->Text->ToString(), densityStr); //density
    Convert_String_to_string(textBox4->Text->ToString(), sizeOfSampleStr); //density
    int graphASize, graphBSize, sizeOfSample;
    float density;
    graphASize = std::stoi(graphASizeStr);
    graphBSize = std::stoi(graphBSizeStr);
    density = std::stof(densityStr);
    sizeOfSample = std::stoi(sizeOfSampleStr);

    //валидаци€ введенных данных
    if (!isInputValid(graphASize, 3, 99, 2))
        return System::Void();
    if (!isInputValid(graphBSize, 3, 99, 3))
        return System::Void();
    if (!isInputValid(density, 0.1, 1.0, 4))
        return System::Void();
    if (!isInputValid(sizeOfSample, 1, 99, 5))
        return System::Void();
    if (graphASize < graphBSize)
        std::swap(graphASize, graphBSize);

    //оценка сложности задачи
    std::string buf;
    buf = "„исло размещений вершин большого графа A по n местам малого графа B: ";
    int bufInt = (fact(graphASize) / fact(graphASize - graphBSize));
    buf += std::to_string(bufInt);
    MessageBox::Show(Convert_string_to_String(buf));

    //генераци€ выборки
    this->sampleGraphBig->clear();
    this->sampleGraphSmall->clear();
    this->listBox1->Items->Clear();

    for (int i = 0; i < sizeOfSample; i++)
    {
        graphBig = new std::vector<std::vector<int>>(genGraphWithDensity(graphASize, density));
        graphSmall = new std::vector<std::vector<int>>(genGraphWithDensity(graphBSize, density));
        sampleGraphBig->push_back(*graphBig);
        sampleGraphSmall->push_back(*graphSmall);
        listBox1->Items->Add("ѕара " + (i + 1));
    }
    this->selectedGraphPair = 0;
    graphBig = &((*this->sampleGraphBig)[selectedGraphPair]);
    this->dataGridView1->RowCount = graphBig->size()+1;
    this->dataGridView1->ColumnCount = graphBig->size();
    this->dataGridView2->RowCount = graphSmall->size() + 1;
    this->dataGridView2->ColumnCount = graphSmall->size();
    

    String^ strBuf;
    //dataGridView1->Rows->Clear();
    //отображение выборки
    for (int i = 0; i < (*sampleGraphBig)[selectedGraphPair].size(); i++)
    {
        //dataGridView1->ColumnCount = sampleGraphBig->back().size();
        //for (int j = 0; j < sampleGraphBig->back().size(); j++)
        //{
        //    //dataGridView1->Column
        //}
        //dataGridView1->Rows->Add();
        for (int j = 0; j < (*sampleGraphBig)[selectedGraphPair][i].size(); j++)
        {
            strBuf += (*sampleGraphBig)[selectedGraphPair][i][j].ToString();
            //String^ bufStr = sampleGraphBig->back()[i][j].ToString();
            //dataGridView1->Rows[i]->Cells[j]->Value = bufStr;
        }
        strBuf += "\n";
    }
    //MessageBox::Show(strBuf);

    return System::Void();
}
//импорт выборки
System::Void DotNet2::FormSampleData::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
//экспорт выборки
System::Void DotNet2::FormSampleData::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
//переход к метаоптимизации
System::Void DotNet2::FormSampleData::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
    FormMeta^ formMeta = gcnew FormMeta();
    this->Hide();
    formMeta->Show();
}
//переход к анализу
System::Void DotNet2::FormSampleData::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    FormAnalysis^ formAnalysis = gcnew FormAnalysis(*sampleGraphBig, *sampleGraphSmall);
    this->Hide();
    formAnalysis->Show();
}



