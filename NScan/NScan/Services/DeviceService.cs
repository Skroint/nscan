using NScanCore.Model;
using SharpPcap;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NScan.Services
{
    internal class DeviceService
    {
        //internal List<Device> LoadDevices()
        //{
        //    var devices = CaptureDeviceList.Instance;

        //    foreach (var dev in devices)
        //    {
        //        Console.WriteLine("{0}\n", dev.ToString());

        //    }
        //}

        //private Device FromPcapDevice(ILiveDevice device)
        //{
        //    return new Device()
        //    {
        //        Name = GetFriendlyName(device),
        //        PcapDevice = device,
        //    };
        //}

        //private string GetFriendlyName(ILiveDevice device)
        //{
        //    var lines = device.ToString().Split(new []
        //    {
        //        "\r\n", "\n"
        //    }, StringSplitOptions.RemoveEmptyEntries);
        //    var friendlyNameLine = lines.FirstOrDefault(l => l.Contains("Friendy"));

        //}

    }
}
