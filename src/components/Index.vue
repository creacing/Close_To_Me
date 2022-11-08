<template>
  <div id="sidebar">
    <div>
      <h2 class="title">文章目录</h2>
    </div>

    <div class="content slide-up-big-in" data-title="文章目录">
      <ol>
        <li class="index-item" v-for="(item, index) in sideIndex" :key="item">
          <a href="#">
            <span v-html="item" class="index-title"></span>
          </a>
        </li>
      </ol>
    </div>
  </div>
</template>
<script setup>
import { defineProps, toRefs } from "vue";

const props = defineProps({
  sideIndex: {
    type: Array,
    default: () => [],
  },
});

const { sideIndex } = toRefs(props);
</script>
<style scoped lang='scss'>
#sidebar {
  width: 15rem !important;
}

#sidebar .index-item {
  padding: 0 2rem;
}

.content .index-item {
  font-size: 1em;
  line-height: 1.8;
  overflow: hidden;
  text-overflow: ellipsis;
}

#sidebar .title {
  text-align: center;
}
#sidebar .content .index-item {
  display: flex;
}

.index-title {
  font-size: 0.7rem !important;
}

#sidebar {
  position: static;
  top: 0;
  bottom: 0;
  transition: all 0.2s ease-in-out 0s;
}

@media (max-width: 991px) {
  #sidebar {
    font-size: 0.8rem;
    background: var(--grey-1);
    z-index: 99;
  }
}
</style>