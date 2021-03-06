#ifndef FWCore_ParameterSet_ProcessDesc_h
#define FWCore_ParameterSet_ProcessDesc_h

#include <memory>
#include <string>
#include <vector>

namespace edm {

  class ParameterSet;

  class ProcessDesc {

  public:
    explicit ProcessDesc(std::shared_ptr<ParameterSet> pset);

    /// construct from the configuration language string
    explicit ProcessDesc(std::string const& config);

    ~ProcessDesc();

    /// get the parameter set
    std::shared_ptr<ParameterSet> getProcessPSet() const;

    /// get the descriptions of the services
    std::shared_ptr<std::vector<ParameterSet> > getServicesPSets() const;

    void addService(ParameterSet& pset);
    /// add a service as an empty pset
    void addService(std::string const& service);
    /// add a service if it's not already there
    void addDefaultService(std::string const& service);
    /// add a service and replace it if it's already there
    void addForcedService(std::string const& service);
    /// add some default services and forced services
    void addServices(std::vector<std::string> const& defaultServices,
                     std::vector<std::string> const& forcedServices = std::vector<std::string>());

    std::string dump() const;
  private:
    std::shared_ptr<ParameterSet> pset_;
    std::shared_ptr<std::vector<ParameterSet> > services_;
  };
}

#endif
