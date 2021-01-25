using System;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;


namespace SimpleMessenger
{
    public partial class Messenger : Form
    {
        /* [TODO]
        * 클라이언트에 해당하는 폼입니다.
        * 폼 디자이너를 이용하여 적절한 컨트롤들을 배치하고 여러 상호작용 이벤트들을 처리하여 
        * 프로그램을 완성해보세요 :)
        */
        TcpClient client = null;
        NetworkStream stream = null;
        int port;
        string name;

        Socket mainSock;

        public Messenger()
        {
            InitializeComponent();
            mainSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
        }

        private async Task Send(){
            byte[] data = new byte[32768];
            data = Encoding.ASCII.GetBytes(DateTime.Now.ToString("h:mm:ss") + " " +name + " : "  + input_box.Text);
            
            if (client == null) return;
            await Task.Run(async () =>
            {
                while (true)
                {
                    while (stream == null)
                    {
                        await Task.Delay(10);
                    }
                    try
                    {
                        stream.Write(data, 0, data.Length);
                        break;
                    }
                    catch (SocketException se) {break; }
                }
            });        
        }
        private async Task ReceiveMessage()
        {
            /* [TODO]
             * client와 stream에 적절한 값을 입력하여 서버로부터 메세지를 받아옵니다.
             * 해당 메소드를 사용하지 않아도 무방합니다.
             */
            if (client == null) return;
            await Task.Run(async () =>
            {
                byte[] data = new byte[32768];
                string responseData = "";
                while (true)
                {
                    while (stream == null)
                    {
                        await Task.Delay(10);
                    }
                    try
                    {
                        int bytes = stream.Read(data, 0, data.Length);
                        responseData = Encoding.Default.GetString(data, 0, bytes);
                        if(name == "A")
                        {
                            if(outLabel.InvokeRequired){
                                outLabel.BeginInvoke(new Action(()=> outLabel.Text += Environment.NewLine + ">>"  + responseData));
                            }
                            else{
                                outLabel.Text += Environment.NewLine + ">>"  + responseData;
                            }
                        }    
                        
                        if (name == "B")
                        {
                            if(outLabel.InvokeRequired){
                                outLabel.BeginInvoke(new Action(()=> outLabel.Text += Environment.NewLine + ">>" + responseData));
                            }
                            else{
                                outLabel.Text += Environment.NewLine + ">>"  + responseData;
                            }
                        }
                    }
                    catch (SocketException se) { break; }
                }
            });
        }

        private async void connect1_Click(object sender, EventArgs e)
        {
            if(btn_a.Checked == true)
            {
                port = 5001;
                name = "A";
            }
            if(btn_b.Checked == true)
            {
                port = 5002;
                name = "B";
            }

            IPEndPoint clientAddress = new IPEndPoint(IPAddress.Parse(Get_MyIP()), port);
            client = new TcpClient(clientAddress);
            client.Connect(Get_MyIP(), 5050);
            stream = client.GetStream();
            

            outLabel.Text += Environment.NewLine + ">>" + DateTime.Now.ToString("yyyy-MM-dd tt h:mm:ss") + "              " + name + "님께서 접속하셨습니다.";
            

            connect_string.Text = "접속 성공";
            btn_a.Dispose();
            btn_b.Dispose();
            connect1.Dispose();
            await ReceiveMessage();
        }

        public string Get_MyIP()
        {
            IPHostEntry host = Dns.GetHostEntry(Dns.GetHostName());
            string ClientIP = string.Empty;
            for (int i = 0; i < host.AddressList.Length; i++)
            {
                if (host.AddressList[i].AddressFamily == AddressFamily.InterNetwork)
                {
                    ClientIP = host.AddressList[i].ToString();
                }
            }
            return ClientIP;
        }


        private async void input_button_Click(object sender, EventArgs e)
        {
            await Send();
            outLabel.Text += "\r\n>>" + DateTime.Now.ToString("h:mm:ss ") + name + " : " + input_box.Text;
            input_box.Text = "";
        }


        private void outLabel_TextChanged(object sender, EventArgs e)
        {
            outLabel.SelectionStart = outLabel.Text.Length;
            outLabel.ScrollToCaret();
        }

        
    }
}
