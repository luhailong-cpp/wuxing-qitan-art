#include "scene_node_service.h"
#include <future>
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE

SceneNodeGrpcImpl::SceneNodeGrpcImpl(muduo::net::EventLoop& loop)
    : loop_(loop)
{
}

void SceneNodeGrpcImpl::HandleCreateScene(const ::CreateSceneRequest* request,
    ::CreateSceneResponse* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE}
}

void SceneNodeGrpcImpl::HandleDestroyScene(const ::DestroySceneRequest* request)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE}
}

void SceneNodeGrpcImpl::HandleReleasePlayer(const ::scene_node::ReleasePlayerRequest* request)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE}
}

void SceneNodeGrpcImpl::HandlePrepareBattle(const ::PrepareBattleRequest* request,
    ::PrepareBattleResponse* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE}
}

void SceneNodeGrpcImpl::HandleCancelBattlePrepare(const ::CancelBattlePrepareRequest* request)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE}
}

void SceneNodeGrpcImpl::HandleAssetDebit(const ::AssetOpRequest* request,
    ::AssetOpResponse* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE}
}

void SceneNodeGrpcImpl::HandleAssetAbortDebit(const ::AssetOpRequest* request,
    ::AssetOpResponse* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE}
}

void SceneNodeGrpcImpl::HandleAssetCredit(const ::AssetOpRequest* request,
    ::AssetOpResponse* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE}
}

grpc::Status SceneNodeGrpcImpl::CreateScene(grpc::ServerContext* /*context*/,
    const ::CreateSceneRequest* request,
    ::CreateSceneResponse* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
    std::promise<void> promise;
    auto future = promise.get_future();

    loop_.runInLoop([request, response, &promise]
                    {
        HandleCreateScene(request, response);
        promise.set_value(); });

    future.get();
    return grpc::Status::OK;
}

grpc::Status SceneNodeGrpcImpl::DestroyScene(grpc::ServerContext* /*context*/,
    const ::DestroySceneRequest* request,
    ::Empty* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
    std::promise<void> promise;
    auto future = promise.get_future();

    loop_.runInLoop([request, &promise]
                    {
        HandleDestroyScene(request);
        promise.set_value(); });

    future.get();
    return grpc::Status::OK;
}

grpc::Status SceneNodeGrpcImpl::ReleasePlayer(grpc::ServerContext* /*context*/,
    const ::scene_node::ReleasePlayerRequest* request,
    ::Empty* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
    std::promise<void> promise;
    auto future = promise.get_future();

    loop_.runInLoop([request, &promise]
                    {
        HandleReleasePlayer(request);
        promise.set_value(); });

    future.get();
    return grpc::Status::OK;
}

grpc::Status SceneNodeGrpcImpl::PrepareBattle(grpc::ServerContext* /*context*/,
    const ::PrepareBattleRequest* request,
    ::PrepareBattleResponse* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
    std::promise<void> promise;
    auto future = promise.get_future();

    loop_.runInLoop([request, response, &promise]
                    {
        HandlePrepareBattle(request, response);
        promise.set_value(); });

    future.get();
    return grpc::Status::OK;
}

grpc::Status SceneNodeGrpcImpl::CancelBattlePrepare(grpc::ServerContext* /*context*/,
    const ::CancelBattlePrepareRequest* request,
    ::Empty* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
    std::promise<void> promise;
    auto future = promise.get_future();

    loop_.runInLoop([request, &promise]
                    {
        HandleCancelBattlePrepare(request);
        promise.set_value(); });

    future.get();
    return grpc::Status::OK;
}

grpc::Status SceneNodeGrpcImpl::AssetDebit(grpc::ServerContext* /*context*/,
    const ::AssetOpRequest* request,
    ::AssetOpResponse* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
    std::promise<void> promise;
    auto future = promise.get_future();

    loop_.runInLoop([request, response, &promise]
                    {
        HandleAssetDebit(request, response);
        promise.set_value(); });

    future.get();
    return grpc::Status::OK;
}

grpc::Status SceneNodeGrpcImpl::AssetAbortDebit(grpc::ServerContext* /*context*/,
    const ::AssetOpRequest* request,
    ::AssetOpResponse* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
    std::promise<void> promise;
    auto future = promise.get_future();

    loop_.runInLoop([request, response, &promise]
                    {
        HandleAssetAbortDebit(request, response);
        promise.set_value(); });

    future.get();
    return grpc::Status::OK;
}

grpc::Status SceneNodeGrpcImpl::AssetCredit(grpc::ServerContext* /*context*/,
    const ::AssetOpRequest* request,
    ::AssetOpResponse* response)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
    std::promise<void> promise;
    auto future = promise.get_future();

    loop_.runInLoop([request, response, &promise]
                    {
        HandleAssetCredit(request, response);
        promise.set_value(); });

    future.get();
    return grpc::Status::OK;
}
