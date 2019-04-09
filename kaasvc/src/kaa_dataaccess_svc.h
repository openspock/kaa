/**
 * Copyright 2019, Kaa
 *
 **/

#include "kaa.grpc.pb.h"
#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

namespace kaa {

class kaa_service_impl final: public kaa::kaa_data_access::Service {
public:
  grpc::Status
  write(grpc::ServerContext *ctx,
      const kaa::write_req *req,
      kaa::write_res *res) override;
};

void run_kaa();

}
