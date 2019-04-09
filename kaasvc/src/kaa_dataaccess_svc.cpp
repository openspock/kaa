/**
 * Copyright kaa, 2019
 *
 **/

#include "kaa_dataaccess_srv.h"

grpc::Status kaa::kaa_service_impl::write(grpc::ServerContext *ctx,
    const kaa::write_req *req,
    kaa::write_res *res) {
  return grpc::Status::OK;
}

void kaa::run_kaa() {
  std::string svc_addr("localhost:49999");
  kaa::kaa_service_impl kaa_svc;

  grpc::ServerBuilder builder;
  builder.AddListeningPort(svc_addr, grpc::InsecureServerCredentials());
  builder.RegisterService(&kaa_svc);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "kaa up and running on " << svc_addr << "\n";
  server->Wait();
}
