using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using CommandMessenger;
using CommandMessenger.TransportLayer;
using WpfReflowMonitor.Annotations;

namespace WpfReflowMonitor
{
    enum Command
    {
        Eerste,
        AReceivedPid,
        StartLogging,
        Log,
    };

    partial class MainWindow 
    {


        private SerialTransport _serialTransport;
        private CmdMessenger _cmdMessenger;

        // Setup function
        public void Setup()
        {
            // Create Serial Port object
            // Note that for some boards (e.g. Sparkfun Pro Micro) DtrEnable may need to be true.
            _serialTransport = new SerialTransport
            {
                CurrentSerialSettings = { PortName = "COM4", BaudRate = 9600, DtrEnable = false } // object initializer
            };

            // Initialize the command messenger with the Serial Port transport layer
            _cmdMessenger = new CmdMessenger(_serialTransport)
            {
                BoardType = BoardType.Bit16 // Set if it is communicating with a 16- or 32-bit Arduino board
            };

            // Set Received command strategy that removes commands that are older than 1 sec
            _cmdMessenger.AddReceiveCommandStrategy(new StaleGeneralStrategy(1000));

            // Attach the callbacks to the Command Messenger
            AttachCommandCallBacks();

            // Start listening
            _cmdMessenger.StartListening();

        }


        // Exit function
        public void Exit()
        {
            // Stop listening
            _cmdMessenger.StopListening();

            // Dispose Command Messenger
            _cmdMessenger.Dispose();

            // Dispose Serial Port object
            _serialTransport.Dispose();
        }

        /// Attach command call backs. 
        private void AttachCommandCallBacks()
        {


            _cmdMessenger.Attach((int)Command.Log, OnPlotDataPoint);
        }


      
        // Callback function that plots a data point for ADC 1 and ADC 2
        private void OnPlotDataPoint(ReceivedCommand arguments)
        {
            var time = arguments.ReadFloatArg();
            time = time/100;

            var realTemp = arguments.ReadFloatArg()/100;
            Point p1 = new Point(time,realTemp);
            this.Dispatcher.Invoke((Action)(() =>
            {
                wantedPoints.Add(p1);
            }));


            var wantedTemp = arguments.ReadFloatArg();
            Point p2 = new Point(time, wantedTemp);

        }



        
    }
}
