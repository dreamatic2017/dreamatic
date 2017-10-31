#include <gtk-2.0/gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

struct input_widget{
        GtkWidget *window; //主窗体
        GtkWidget *lable_1;
        GtkWidget *lable_2;
        GtkWidget *lable_3;
        GtkWidget *lable_4;
        GtkWidget *entry_2;
        GtkWidget *entry_3;
        GtkWidget *entry_4;
        GtkWidget *button_1;
        GtkWidget *button_2;
        GtkWidget *vbox;
        GtkWidget *hbox_1;
        GtkWidget *hbox_2;
        GtkWidget *hbox_3;
        GtkWidget *hbox_4;

}wgt;

void gtk_win_destroy(GtkWidget *widget,gpointer data)
{
        gtk_main_quit();
}

void gtk_win_button1(GtkWidget *widget,gpointer data)
{
       struct input_widget *wgt;
       wgt=(struct input_widget *)data;
       gtk_label_set_text(GTK_LABEL(wgt->lable_1),"button1");
}

void gtk_win_button2(GtkWidget *widget,gpointer data)
{
    gchar *str;
    struct input_widget *wgt;
    wgt = (struct input_widget*)data; //init wgt

    str = gtk_entry_get_text(GTK_ENTRY(wgt->entry_2));//获取文本框输入
    //str=strcat(str,"hello");//字符串连接

    float x;
    x=atof(str)*2;//atof函数转换字符串为数值

    //printf("str = %.2f\n", x);
    gtk_label_set_text(GTK_LABEL(wgt->lable_1),str);
}


void init_input_widget()
{
	wgt.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	wgt.lable_1= gtk_label_new("this is the GTK entry testing prog");
	wgt.lable_2= gtk_label_new("data1");
	wgt.lable_3= gtk_label_new("data2");
	wgt.lable_4= gtk_label_new("data3");
    wgt.button_1 = gtk_button_new_with_label("send");
    wgt.button_2 = gtk_button_new_with_label("exit");
    wgt.entry_2 = gtk_entry_new_with_max_length(16);
    wgt.entry_3 = gtk_entry_new_with_max_length(16);
    wgt.entry_4 = gtk_entry_new_with_max_length(16);
    wgt.vbox = gtk_vbox_new(FALSE,20);
    wgt.hbox_1 = gtk_hbox_new(FALSE,20);
    wgt.hbox_2 = gtk_hbox_new(FALSE,20);
    wgt.hbox_3 = gtk_hbox_new(FALSE,20);
    wgt.hbox_4 = gtk_hbox_new(FALSE,20);

    //设置窗体
    gtk_window_set_title(GTK_WINDOW(wgt.window),"hello world!");
    gtk_window_set_resizable(GTK_WINDOW(wgt.window),FALSE);

    //设置布局盒子

    gtk_box_pack_start(GTK_BOX(wgt.hbox_2),wgt.lable_2,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(wgt.hbox_2),wgt.entry_2,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(wgt.hbox_3),wgt.lable_3,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(wgt.hbox_3),wgt.entry_3,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(wgt.hbox_4),wgt.lable_4,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(wgt.hbox_4),wgt.entry_4,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(wgt.hbox_1),wgt.button_1,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(wgt.hbox_1),wgt.button_2,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(wgt.vbox),wgt.lable_1,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(wgt.vbox),wgt.hbox_2,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(wgt.vbox),wgt.hbox_3,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(wgt.vbox),wgt.hbox_4,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(wgt.vbox),wgt.hbox_1,TRUE,FALSE,10);

    //设置事件回调函数
    g_signal_connect(GTK_OBJECT(wgt.window),"destroy",GTK_SIGNAL_FUNC(gtk_win_destroy),NULL);
    g_signal_connect(GTK_OBJECT(wgt.button_1),"clicked",GTK_SIGNAL_FUNC(gtk_win_button1),&wgt);
    g_signal_connect(GTK_OBJECT(wgt.button_2),"clicked",GTK_SIGNAL_FUNC(gtk_win_button2),&wgt);

    gtk_container_add(GTK_CONTAINER(wgt.window),wgt.vbox);
    gtk_widget_show_all(wgt.window);

//设置几个初始的数值
    gtk_entry_set_text(wgt.entry_2,"默认");
    gtk_entry_set_text(wgt.entry_3,"default");
    gtk_entry_set_text(wgt.entry_4,"请输入数字");

}

int main(int argc,char *argv[])
{
    gtk_init(&argc,&argv);
    init_input_widget();
    gtk_main();
    return 0;
}
