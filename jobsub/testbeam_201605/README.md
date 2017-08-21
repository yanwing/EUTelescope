README FILE TO BE UPDATED SOON

Grand Master

- Michaela Queitsch-Maitland (michaela.queitsch-maitland@desy.de)

Core Developers

- Edoardo Rossi (edoardo.rossi@desy.de)
- John Stakely Keller (john.keller@desy.de)

Developers

- Veronica Fabiani (veronica.fabiani@cern.ch)

If you want to be able to push your code, send an e-mail to one of the core developers. This is not necessary if you just want to download the code.

##########################################

                HOW TO
            
##########################################

The input file is the final root file produced by EUTelescope after the track fitting.

The first codes filters the information of the root files and calculates some crucial quantities to run the second code.
On lxplus or NAF, to use it, it is enough to setup the ATLAS environment (setupATLAS) and ROOT (localSetupROOT) and:

./make_testbeam_analysis.sh --config your_settings.config --input your_input_ntuple.root 

Pay attention, the config file is not the one used in EUTelescope. In this config file, apart from the trivial quantities, it is necessary to specify:
DUT_FEI4_pos: this is the spatial difference between the FEI4 plane and the DUT. E.g. if the DUT is the 4th plane and the FEI4 is the 6th, this quantity is 2.
beam_offset: this quantity is calculated as half DUT width - local_dist_DUT (quantity specified in EUTelescope)
rotated: this quantity is 1 if the strips are orientated along y and 0 along x
Moreover, the quantities min_time and max_time apply a timing cut to the plots, but it will be necessary to apply the cut again in the second code to have it in the s-curves.
If you want to take a look to how the NTuple looks, add --debug to the command.