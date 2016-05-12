using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CommandMessenger;
using CommandMessenger.TransportLayer;

namespace ReflowService
{
    enum Command
    {
        CSendTempData,
        CReceivePid
    }

    class SerialMessenger
    {
        private SerialTransport serialTransport;
        private CmdMessenger cmdMessenger;
        private int setpoint;
        private int currentTemp;
        private int pid = 24;

        public SerialMessenger()
        {
            serialTransport = new SerialTransport();
            serialTransport.CurrentSerialSettings.PortName = "COM3";
            serialTransport.CurrentSerialSettings.BaudRate = 9600;
            serialTransport.CurrentSerialSettings.DtrEnable = false;

            cmdMessenger = new CmdMessenger(serialTransport);
            cmdMessenger.BoardType = BoardType.Bit16;
            AttachCommandCallBacks();
            cmdMessenger.StartListening();

        }

        private void AttachCommandCallBacks()
        {
            cmdMessenger.Attach((int)Command.CSendTempData, NewTempData);
        }

        void NewTempData(ReceivedCommand arguments)
        {
            Console.Write("huidige temperatuur:");
            Console.WriteLine(arguments.ReadInt32Arg());
            Console.Write("huidig setpoint:");
            Console.WriteLine(arguments.ReadInt32Arg());
        }

        public void SendPid()
        {
            var command = new SendCommand((int)Command.CReceivePid, pid);
            cmdMessenger.SendCommand(command);
        }
    }


}
