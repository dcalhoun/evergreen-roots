let str = ReasonReact.stringToElement;

type state = {items: Listings.items};

let component = ReasonReact.reducerComponent("Index");

let make = (_children) => {
  let getInitialProps = () =>
    Js.Promise.(
      Endpoints.fetchListings()
      |> then_(Fetch.Response.json)
      |> then_((json) => {items: json##results})
      |> resolve
    );
  {
    ...component,
    reducer: ((), _) => ReasonReact.NoUpdate,
    render: ({state: {items}}) =>
      <div>
        <span> (str("Home")) </span>
        <About />
        (List.length(items) > 0 ? <Listings items /> : <Loading />)
      </div>
  }
};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
