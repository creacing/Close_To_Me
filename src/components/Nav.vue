<template>
  <Neko :isShow="isShow" :isSun="isSun" />
  <div class="inner">
    <Brand />

    <nav id="nav" :class="navBottom === 2 ? '' : navBottom === 1 ? 'show down' : 'show up'">
      <div class="inner">
        <div class="toggle" @click="showSidebar">
          <div class="lines" aria-label="切换导航栏">
            <span class="line"></span>
            <span class="line"></span>
            <span class="line"></span>
          </div>
        </div>
        <ul class="menu">
          <li class="item" :class="item.liClass" v-for="item in nav" :key="item">
            <RouterLink :to="item.link" data-pjax-state :class="item.aClass" :rel="item.rel">
              <i class="ic" :class="item.iClass"></i>
              {{ item.name }}
            </RouterLink>
            <ul class="submenu" v-if="item.children.length > 0">
              <li class="item" v-for="child in item.children" :key="child">
                <RouterLink :to="child.link" :rel="child.rel" data-pjax-state :class="child.iClass">
                  <i class="ic" :class="child.iClass"></i>
                  {{ child.name }}
                </RouterLink>
              </li>
            </ul>
          </li>
        </ul>
        <ul class="right">
          <li class="item theme">
            <i v-if="isSun" class="ic i-sun" @click="changeTheme" data-theme></i>
            <i v-if="!isSun" class="ic i-moon" @click="changeTheme" data-theme="dark"></i>
          </li>
          <li class="item search">
            <i class="ic i-search" @click="searchArticles"></i>
          </li>
        </ul>
      </div>
    </nav>
  </div>
  <BgImage />
  <!-- <PlayMusic /> -->
  <Search :showSearch="showSearch" @close="closeSearchDialog" />
</template>
<script setup>
import { RouterLink } from "vue-router";
import Neko from "./Neko.vue";
import Search from "./Search.vue";
import config from "./../../public/config.js";
import Brand from "./Brand.vue";
import BgImage from "./BgImage.vue";
// import PlayMusic from "./PlayMusic.vue";
import { transition } from "@/utils/tool.js";
import { onMounted, ref, onUnmounted } from "vue";
const { nav } = config;
//切换黑白背景
const isSun = ref(true); // 白天黑夜 default 白天
const isShow = ref(false); // 是否显示 default 不显示
const changeTheme = () => {
  const HTML = document.documentElement;

  isSun.value = !isSun.value;
  isShow.value = !isShow.value;
  //background color
  if (!isSun.value) {
    HTML.setAttribute("data-theme", "dark");
  } else {
    HTML.setAttribute("data-theme", "");
  }
  // switch white and dark
  setTimeout(() => {
    isSun.value = !isSun.value;
  }, 200);
  //hidden animation ,stop for 2500ms
  setTimeout(() => {
    isShow.value = !isShow.value;
    isSun.value = !isSun.value;
  }, 2500);
};
//search component
const showSearch = ref(false);
const searchArticles = () => {
  showSearch.value = true;
};
const closeSearchDialog = (value) => {
  showSearch.value = value;
};

const navBottom = ref(2);
let scroll = 0;
let offsetWave = null;

onMounted(() => {
  offsetWave = document.getElementById("waves").offsetTop;
  window.addEventListener("scroll", scrollTop, true);
});

const scrollTop = () => {
  const newScroll =
    document.documentElement.scrollTop || document.body.scrollTop;

  if (newScroll > scroll) {
    //往下拉
    newScroll < offsetWave ? (navBottom.value = 2) : (navBottom.value = 1);
  } else {
    // 往上拉
    newScroll < offsetWave ? (navBottom.value = 2) : (navBottom.value = 0);
  }
  scroll = newScroll;
};

onUnmounted(() => {
  window.removeEventListener("scroll", scrollTop)
})

const showSidebar = () => {

}
</script>

<style lang="scss" scoped>
</style>
