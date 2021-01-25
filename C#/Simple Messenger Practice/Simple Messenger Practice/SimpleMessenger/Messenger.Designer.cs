using System;
using System.Drawing;
using System.Windows.Forms;

namespace SimpleMessenger
{
    partial class Messenger
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.connect1 = new System.Windows.Forms.Button();
            this.outLabel = new System.Windows.Forms.TextBox();
            this.btn_a = new System.Windows.Forms.RadioButton();
            this.btn_b = new System.Windows.Forms.RadioButton();
            this.connect_string = new System.Windows.Forms.TextBox();
            this.input_button = new System.Windows.Forms.Button();
            this.input_box = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // connect1
            // 
            this.connect1.Location = new System.Drawing.Point(805, 44);
            this.connect1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.connect1.Name = "connect1";
            this.connect1.Size = new System.Drawing.Size(86, 29);
            this.connect1.TabIndex = 0;
            this.connect1.Text = "접 속";
            this.connect1.Click += new System.EventHandler(this.connect1_Click);
            // 
            // outLabel
            // 
            this.outLabel.BackColor = System.Drawing.SystemColors.Window;
            this.outLabel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.outLabel.Location = new System.Drawing.Point(11, 125);
            this.outLabel.Multiline = true;
            this.outLabel.Name = "outLabel";
            this.outLabel.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.outLabel.Size = new System.Drawing.Size(880, 297);
            this.outLabel.TabIndex = 0;
            this.outLabel.TextChanged += new System.EventHandler(this.outLabel_TextChanged);
            // 
            // btn_a
            // 
            this.btn_a.Location = new System.Drawing.Point(750, 25);
            this.btn_a.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btn_a.Name = "btn_a";
            this.btn_a.Size = new System.Drawing.Size(58, 30);
            this.btn_a.TabIndex = 1;
            this.btn_a.Text = "A";
            // 
            // btn_b
            // 
            this.btn_b.Location = new System.Drawing.Point(750, 63);
            this.btn_b.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btn_b.Name = "btn_b";
            this.btn_b.Size = new System.Drawing.Size(58, 30);
            this.btn_b.TabIndex = 2;
            this.btn_b.Text = "B";
            // 
            // connect_string
            // 
            this.connect_string.BackColor = System.Drawing.SystemColors.Control;
            this.connect_string.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.connect_string.Location = new System.Drawing.Point(518, 51);
            this.connect_string.Multiline = true;
            this.connect_string.Name = "connect_string";
            this.connect_string.Size = new System.Drawing.Size(226, 25);
            this.connect_string.TabIndex = 3;
            this.connect_string.Text = "접속할 클라이언트를 선택하세요";
            // 
            // input_button
            // 
            this.input_button.Location = new System.Drawing.Point(743, 434);
            this.input_button.Name = "input_button";
            this.input_button.Size = new System.Drawing.Size(148, 70);
            this.input_button.TabIndex = 4;
            this.input_button.Text = "전 송";
            this.input_button.UseVisualStyleBackColor = true;
            this.input_button.Click += new System.EventHandler(this.input_button_Click);
            // 
            // input_box
            // 
            this.input_box.Location = new System.Drawing.Point(11, 434);
            this.input_box.Multiline = true;
            this.input_box.Name = "input_box";
            this.input_box.Size = new System.Drawing.Size(718, 70);
            this.input_box.TabIndex = 5;
            // 
            // Messenger
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(903, 560);
            this.Controls.Add(this.input_box);
            this.Controls.Add(this.input_button);
            this.Controls.Add(this.connect_string);
            this.Controls.Add(this.connect1);
            this.Controls.Add(this.outLabel);
            this.Controls.Add(this.btn_a);
            this.Controls.Add(this.btn_b);
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "Messenger";
            this.Text = "Simple Messenger";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private EventHandler connect1_ClickAsync()
        {
            throw new NotImplementedException();
        }

        #endregion

        private Button connect1;        //접속 버튼
        private TextBox outLabel;         //출력창
        private RadioButton btn_a;      // A
        private RadioButton btn_b;      // B
        private TextBox connect_string; //접속할 클라이언트를 선택하세요
        private Button input_button;    // 전송 버튼
        private TextBox input_box;      // 입력 창
    }
}

