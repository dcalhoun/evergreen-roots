let str = ReasonReact.stringToElement;

type action =
  | Loaded(ListingData.items)
  | Loading;

type state = {
  status: string,
  items: ListingData.items
};

let component = ReasonReact.reducerComponent("Index");

/* TODO: Attempt to use dipsatch and state props */
let make = (~items: ListingData.items, ~status: string=Status.idle, _children) => {
  let loadListings = ({ReasonReact.reduce}) => {
    ListingData.fetch(reduce((payload) => Loaded(payload))) |> ignore;
    reduce((_items) => Loading, items)
  };
  {
    ...component,
    initialState: () => {status, items},
    reducer: (action, state) =>
      switch action {
      | Loaded(items) => ReasonReact.Update({items, status: Status.fetched})
      | Loading => ReasonReact.Update({...state, status: Status.fetching})
      },
    didMount: (self) => {
      status == Status.idle ?
        loadListings(self) : self.reduce((items) => Loaded(items), items);
      ReasonReact.NoUpdate
    },
    render: (self) =>
      <Layout>
        <Next.Head> <title> (str("Evergreen Roots")) </title> </Next.Head>
        <About />
        /* TODO: Why can I not open Status and combine with switch? */
        (
          switch self.state.status {
          | "ERROR" => <Error message="Unable to load product listings." />
          | "FETCHED" => <Listings items=self.state.items />
          | "FETCHING"
          | _ => <Loading />
          }
        )
      </Layout>
  }
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) =>
      make(
        ~status=jsProps##status,
        ~items=jsProps##items |> ListingData.Decode.items,
        [||]
      )
  );
