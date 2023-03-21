#pragma once

#include <QtWidgets/QWidget>
#include "ui_DataTable.h"
#include <QTableWidgetItem>
#include "GetFile.h"

class DataTable : public QWidget
{
    Q_OBJECT

public:
    DataTable(QWidget *parent = nullptr);
    ~DataTable();

private:
    Ui::DataTableClass ui;
};
