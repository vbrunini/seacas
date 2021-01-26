// Copyright(C) 2021 National Technology & Engineering Solutions
// of Sandia, LLC (NTESS).  Under the terms of Contract DE-NA0003525 with
// NTESS, the U.S. Government retains certain rights in this software.
//
// See packages/seacas/LICENSE for details
#ifndef ZE_SystemInterface_h
#define ZE_SystemInterface_h

#include "GetLongOpt.h" // for GetLongOption
#include <string>       // for string

class SystemInterface
{
public:
  SystemInterface();
  ~SystemInterface();

  bool parse_options(int argc, char **argv);

  int debug() const { return debugLevel_; }

  std::string lattice() const { return lattice_; }
  std::string decomp_method() const { return decompMethod_; }

  bool ints32bit() const { return ints32bit_; }
  bool use_netcdf4() const { return useNetcdf4_; }
  bool use_netcdf5() const { return useNetcdf5_; }

  int  compression_level() const { return compressionLevel_; }
  bool zlib() const { return zlib_; }
  bool szip() const { return szip_; }

  int  ranks() const { return ranks_; }
  bool equivalence_nodes() const { return equivalenceNodes_; }

  static void show_version();

  // Make this private eventually...
  std::string outputName_;

private:
  void enroll_options();

  GetLongOption options_; //!< Options parsing

  std::string lattice_{};
  std::string decompMethod_{"RCB"};
  int         debugLevel_{0};
  int         compressionLevel_{0};
  int         ranks_{1};
  bool        ints32bit_{false};
  bool        useNetcdf4_{true};
  bool        useNetcdf5_{false};
  bool        zlib_{true};
  bool        szip_{false};
  bool        equivalenceNodes_{true};
};
#endif
