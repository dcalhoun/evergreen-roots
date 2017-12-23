let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Listing");

let make = (~item: ListingData.item, _children) => {
  ...component,
  render: (_self) =>
    <article>
      <h3> (ReasonReact.stringToElement(item.title)) </h3>
      <h4> (ReasonReact.stringToElement(item.price)) </h4>
    </article>
};
