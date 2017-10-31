#include <gtk-2.0/gtk/gtk.h>

//回调函数，切换进度条的移动方向
void toggle_orientation(GtkWidget *widget, gpointer data)
{
        switch (gtk_progress_bar_get_orientation(GTK_PROGRESS_BAR(data)) ) {
        case GTK_PROGRESS_LEFT_TO_RIGHT:
                gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(data), GTK_PROGRESS_RIGHT_TO_LEFT);
                break;
        case GTK_PROGRESS_RIGHT_TO_LEFT:
                gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(data), GTK_PROGRESS_LEFT_TO_RIGHT);
                break;
        default:
                break;
        }
        return;
}


//回调函数，更新进度条，这样可以看到进度条的移动
void callback(GtkWidget *widget, gpointer data)
{
        gdouble new_val = gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(data)) +0.05;

        if (new_val > 1.0) {
                new_val = 0.0;
        }

        //设置进度条新值
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(data), new_val);

        return;
}

int main(int argc, char *argv[])
{
        //1.gtk环境的初始化
        gtk_init(&argc, &argv);

        //2.创建一个窗口
        GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        //设置窗口的标题
        gtk_window_set_title(GTK_WINDOW(window), "gtk_progress_bar");
        //设置窗口边框宽度
        gtk_container_set_border_width(GTK_CONTAINER(window), 10);

        //3.设置窗口的最小大小
        gtk_widget_set_size_request(window, 300, 200);

        //4.窗口关联destroy信号到gtk_main_quit
        g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

        //5.创建一个垂直容器
        GtkWidget *vbox = gtk_vbox_new(FALSE, 5);
        //将vbox添加到window中
        gtk_container_add(GTK_CONTAINER(window), vbox);

        //6.创建一个进度条
        GtkWidget *progress = gtk_progress_bar_new();
        //将progress添加到vbox中
        gtk_container_add(GTK_CONTAINER(vbox), progress);

        //7.设置进度条的百分比为50%
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress), 0.5);

        //8.设置进度条上显示的文字
        gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress), "some text");

        //9.添加一个button1按钮,切换方向
        GtkWidget *button1 = gtk_button_new_with_label("right to lift");
        gtk_container_add(GTK_CONTAINER(vbox), button1);
        g_signal_connect(button1, "clicked", G_CALLBACK(    toggle_orientation   ), progress);

        //10.添加一个button2，移动进度条
        GtkWidget *button2 = gtk_button_new_with_label("add");
        gtk_container_add(GTK_CONTAINER(vbox), button2);
        g_signal_connect(button2, "clicked", G_CALLBACK(callback), progress);

        //11.显示所欲窗口
        gtk_widget_show_all(window);

        //12.主事件循环
        gtk_main();

        return 0;
}
